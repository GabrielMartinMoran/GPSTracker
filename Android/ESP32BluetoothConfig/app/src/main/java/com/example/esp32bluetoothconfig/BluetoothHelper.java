package com.example.esp32bluetoothconfig;

import android.app.Activity;
import android.app.AlertDialog;
import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothGatt;
import android.bluetooth.BluetoothGattCallback;
import android.bluetooth.BluetoothGattCharacteristic;
import android.bluetooth.BluetoothGattDescriptor;
import android.bluetooth.BluetoothGattService;
import android.bluetooth.BluetoothProfile;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.os.Handler;
import android.util.Log;
import android.widget.ArrayAdapter;
import android.widget.Toast;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.ArrayList;
import java.util.Set;
import java.util.UUID;

import static android.bluetooth.BluetoothAdapter.STATE_CONNECTED;
import static android.content.ContentValues.TAG;

public class BluetoothHelper {

    /*
        REFERENCIA: https://code.tutsplus.com/tutorials/create-a-bluetooth-scanner-with-androids-bluetooth-api--cms-24084
    */

    //La UUID debe conicidir con la del dispositivo a conectarse
    private final UUID SERVICE_UUID = UUID.fromString("6E40F1B0-B5A3-F393-E0A9-E50E24DCCA9E");//"6E400001-B5A3-F393-E0A9-E50E24DCCA9E");
    private final UUID TX_UUID = UUID.fromString("6E40F1B1-B5A3-F393-E0A9-E50E24DCCA9E");//("6E400002-B5A3-F393-E0A9-E50E24DCCA9E");
    private final UUID RX_UUID = UUID.fromString("6E40F1B2-B5A3-F393-E0A9-E50E24DCCA9E");//("6E400003-B5A3-F393-E0A9-E50E24DCCA9E");

    private Context context;
    private BluetoothAdapter BTAdapter;
    private Set<BluetoothDevice> pairedDevices;
    private ArrayList<DeviceItem> deviceItemList;
    public static int REQUEST_BLUETOOTH = 1;
    private BroadcastReceiver bReciever;
    private ConnectThread connectedThread;
    private BluetoothGatt mBluetoothGatt;
    private GattClientCallback gattClientCallback;

    private String readBuffer;

    public String connectedDeviceName;

    private class GattClientCallback extends BluetoothGattCallback {

        Context contextToFinishActivity;
        boolean mtuConfirmed = false;
        GattClientCallback(Context contextToFinishActivity){
            this.contextToFinishActivity = contextToFinishActivity;
        }

        @Override
        public void onConnectionStateChange(BluetoothGatt gatt, int status, int newState) {
            mBluetoothGatt.discoverServices();
            if (newState == BluetoothProfile.STATE_DISCONNECTED) {
                ((Activity)contextToFinishActivity).runOnUiThread(new Runnable() {
                    public void run() {
                        showToastNotification("No se pudo establecer la conexión con el dispositivo. " +
                                "El dispositivo no se encuentra conectado");
                        mBluetoothGatt.disconnect();
                        connectedDeviceName = "";
                    }
                });
            }else if (newState == BluetoothProfile.STATE_CONNECTED) {
                new Thread(new Runnable() {
                    @Override
                    public void run() {
                        int mtuRequestCounter = 0;
                        while (!mtuConfirmed) {
                            mBluetoothGatt.requestMtu(512);
                            mtuRequestCounter++;
                            try {
                                Thread.sleep(1000);
                            } catch (InterruptedException e) {
                                e.printStackTrace();
                            }
                        }
                    }
                }).start();
            }
        }

        @Override
        public void onMtuChanged(BluetoothGatt gatt, int mtu, int status){
            super.onMtuChanged(gatt, mtu, status);
            mtuConfirmed = true;
        }

        @Override
        public void onServicesDiscovered(BluetoothGatt gatt, int status) {
            ((Activity)contextToFinishActivity).runOnUiThread(new Runnable() {
                public void run() {
                    BluetoothGattService mCustomService = null;
                    BluetoothGattCharacteristic txCharacteristic = null;
                    BluetoothGattCharacteristic rxCharacteristic = null;
                    try {
                        //Corroboramos que existan las caracteristicas que necesitamos
                        mCustomService = mBluetoothGatt.getService(SERVICE_UUID);
                        txCharacteristic = mCustomService.getCharacteristic(TX_UUID);
                        rxCharacteristic = mCustomService.getCharacteristic(RX_UUID);
                        if(txCharacteristic == null || rxCharacteristic == null){
                            throw new Exception();
                        }
                    }catch (Exception e){
                        showToastNotification("No se pudo establecer la conexión con el dispositivo. " +
                                "Las caracteristicas requeridas no coinciden.");
                        mBluetoothGatt.disconnect();
                        return;
                    }
                    showToastNotification("Se ha establecido la conexión con el dispositivo.");
                    //Configuramos el receptor para que reciba notificaciones
                    mBluetoothGatt.setCharacteristicNotification(rxCharacteristic, true);
                    BluetoothGattDescriptor descriptor = rxCharacteristic.getDescriptors().get(0);
                    descriptor.setValue(BluetoothGattDescriptor.ENABLE_NOTIFICATION_VALUE);
                    mBluetoothGatt.writeDescriptor(descriptor);

                    connectedDeviceName = gatt.getDevice().getName();

                    //((Activity)contextToFinishActivity).finish();
                    Intent intent = new Intent(((Activity)contextToFinishActivity), DeviceConnectedActivity.class);
                    ((Activity)contextToFinishActivity).startActivity(intent);
                }
            });
        }
        /*
        @Override
        public void onCharacteristicWrite(BluetoothGatt gatt,
                                          BluetoothGattCharacteristic characteristic, int status) {
        }

        @Override
        public final void onCharacteristicRead(final BluetoothGatt gatt,
                                               final BluetoothGattCharacteristic characteristic,
                                               final int status) {
            final byte[] data = characteristic.getValue();
        }*/

        @Override
        public void onCharacteristicChanged(BluetoothGatt gatt,
                                            BluetoothGattCharacteristic characteristic) {
            final byte[] data = characteristic.getValue();
            if(data == null){
                readBuffer = "";
            }else{
                readBuffer = new String(data);
            }

        }
    }


    public BluetoothHelper(Context context){
        this.context = context;
        BTAdapter = BluetoothAdapter.getDefaultAdapter();
        deviceItemList = new ArrayList<DeviceItem>();
    }

    public void configureBroadcastReceiver(ArrayAdapter<DeviceItem> mAdapter){
        bReciever = new BroadcastReceiver() {
            public void onReceive(Context context, Intent intent) {
                String action = intent.getAction();
                if (BluetoothDevice.ACTION_FOUND.equals(action)) {
                    Log.d("DEVICELIST", "Bluetooth device found\n");
                    BluetoothDevice device = intent.getParcelableExtra(BluetoothDevice.EXTRA_DEVICE);
                    // Create a new device item
                    DeviceItem newDevice = new DeviceItem(device.getName(), device.getAddress(), "false");
                    // Add it to our adapter
                    mAdapter.add(newDevice);
                    mAdapter.notifyDataSetChanged();
                }
            }
        };
    }

    public void getPairedDevices(){
        deviceItemList = new ArrayList<DeviceItem>();

        Set<BluetoothDevice> pairedDevices = BTAdapter.getBondedDevices();
        if (pairedDevices.size() > 0) {
            for (BluetoothDevice device : pairedDevices) {
                DeviceItem newDevice= new DeviceItem(device.getName(),device.getAddress(),"false");
                deviceItemList.add(newDevice);
            }
        }

        // If there are no devices, add an item that states so. It will be handled in the view.
        if(deviceItemList.size() == 0) {
            deviceItemList.add(new DeviceItem("No Devices", "", "false"));
        }

        Log.d("DEVICELIST", "DeviceList populated\n");
    }

    public ArrayList<DeviceItem> getDeviceItemList(){
        return deviceItemList;
    }

    public BluetoothAdapter getAdapter(){
        return BTAdapter;
    }

    public BroadcastReceiver getBroadcastReceiver(){
        return bReciever;
    }

    public void verifyBluetoothAdapter(){
        // Phone does not support Bluetooth so let the user know and exit.
        if (BTAdapter == null) {
            new AlertDialog.Builder(context)
                    .setTitle("Not compatible")
                    .setMessage("Your phone does not support Bluetooth")
                    .setPositiveButton("Exit", new DialogInterface.OnClickListener() {
                        public void onClick(DialogInterface dialog, int which) {
                            System.exit(0);
                        }
                    })
                    .setIcon(android.R.drawable.ic_dialog_alert)
                    .show();
        }
    }

    public void connectToDevice(DeviceItem device, Context contextToFinishActivity){
        BluetoothDevice btDevice = BTAdapter.getRemoteDevice(device.getAddress());
        gattClientCallback = new GattClientCallback(contextToFinishActivity);
        mBluetoothGatt = btDevice.connectGatt(context, false, gattClientCallback);
        mBluetoothGatt.connect();
    }

    public void disconnect(){
        mBluetoothGatt.disconnect();
    }

    public void sendData(String value) {
        if (BTAdapter == null || mBluetoothGatt == null) {
            showToastNotification("Ocurrio un error al tratar de enviar el mensaje! No se ha podido establecer conexión con el dispositivo.");
            return;
        }
        /*check if the service is available on the device*/
        BluetoothGattService mCustomService = mBluetoothGatt.getService(SERVICE_UUID);
        if(mCustomService == null){
            showToastNotification("Ocurrio un error al tratar de enviar el mensaje! No se pudo detectar el servicio al cual transmitir información.");
            return;
        }
        //Ponemos en null el buffer de recibidos
        readBuffer = null;
        /*get the read characteristic from the service*/
        BluetoothGattCharacteristic mWriteCharacteristic = mCustomService.getCharacteristic(TX_UUID);
        mWriteCharacteristic.setValue(value.getBytes());//(value,android.bluetooth.BluetoothGattCharacteristic.FORMAT_UINT8,0);
        if(mBluetoothGatt.writeCharacteristic(mWriteCharacteristic) == false){
            //Log.w(TAG, "Failed to write characteristic");
            showToastNotification("Ocurrio un error al tratar de enviar el mensaje!");
        }
    }

    public String receiveData() {
        if (BTAdapter == null || mBluetoothGatt == null) {
            showToastNotification("Ocurrio un error al tratar de enviar el mensaje! No se ha podido establecer conexión con el dispositivo.");
            return null;
        }
        /*check if the service is available on the device*/
        BluetoothGattService mCustomService = mBluetoothGatt.getService(SERVICE_UUID);
        if(mCustomService == null){
            showToastNotification("Ocurrio un error al tratar de enviar el mensaje! No se pudo detectar el servicio al cual transmitir información.");
            return null;
        }
        int timesTried = 0;
        String receivedData = null;
        while(timesTried < 50 && readBuffer == null){
            try{
                Thread.sleep(50);
            }catch (Exception e){
            }
            timesTried ++;
        }
        return readBuffer;
    }

    public void showToastNotification(String message){
        Toast.makeText(context, message, Toast.LENGTH_LONG).show();
    }

    public String makeRequest(String data){
        sendData(data);
        return receiveData();
    }

}
