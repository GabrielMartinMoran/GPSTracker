package com.example.esp32bluetoothconfig;

import android.app.AlertDialog;
import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothGatt;
import android.bluetooth.BluetoothGattCallback;
import android.bluetooth.BluetoothGattCharacteristic;
import android.bluetooth.BluetoothGattService;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
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

public class BluetoothHelper {

    /*
        REFERENCIA: https://code.tutsplus.com/tutorials/create-a-bluetooth-scanner-with-androids-bluetooth-api--cms-24084
    */

    //La UUID debe conicidir con la del dispositivo a conectarse
    private final String BT_UUID_STR = "6E400001-B5A3-F393-E0A9-E50E24DCCA9E";
    private final UUID SERVICE_UUID = UUID.fromString(BT_UUID_STR);

    private Context context;
    private BluetoothAdapter BTAdapter;
    private Set<BluetoothDevice> pairedDevices;
    private ArrayList<DeviceItem> deviceItemList;
    public static int REQUEST_BLUETOOTH = 1;
    private BroadcastReceiver bReciever;
    private ConnectThread connectedThread;
    private BluetoothGatt mBluetoothGatt;

    private class GattClientCallback extends BluetoothGattCallback { }


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

    /**
     *
     * @param device
     * @return Devuelve true si pudo conectarse al dispositivo, y false en caso de que no
     */
    public boolean connectToDevice(DeviceItem device){
        BluetoothDevice btDevice = BTAdapter.getRemoteDevice(device.getAddress());
        //connectedThread = new ConnectThread(btDevice, SERVICE_UUID);
        GattClientCallback gattClientCallback = new GattClientCallback();
        mBluetoothGatt = btDevice.connectGatt(context, false, gattClientCallback);
        //Esperamos 3 segundos para que se inicialize y poder buscar los servicios
        boolean servicesDiscovered = false;
        int timesTried = 0;
        while(timesTried < 3 && !servicesDiscovered){
            try {
                Thread.sleep(3000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            servicesDiscovered = mBluetoothGatt.discoverServices();
            timesTried ++;
        }
        if(!servicesDiscovered){
            showToastNotification("No se pudo establecer la conexión con el dispositivo.");
            disconnect();
        }
        return servicesDiscovered;
    }

    public void disconnect(){
        connectedThread.cancel();
        connectedThread = null;
        mBluetoothGatt = null;
    }


    /*public void sendData(String data) throws IOException {
        sendData(data.getBytes());
    }*/

    /*public void sendData(byte[] data) throws IOException {
        if(connectedThread == null){
            throw new IOException("No device connected");
        }
        ByteArrayOutputStream output = new ByteArrayOutputStream(4);
        output.write(data);
        OutputStream outputStream = connectedThread.getSocket().getOutputStream();
        outputStream.write(output.toByteArray());
    }*/

    public int receiveData() throws IOException{
        if(connectedThread == null){
            throw new IOException("No device connected");
        }
        byte[] buffer = new byte[4];
        ByteArrayInputStream input = new ByteArrayInputStream(buffer);
        InputStream inputStream = connectedThread.getSocket().getInputStream();
        inputStream.read(buffer);
        return input.read();
    }

    public void sendData(String value) {
        if (BTAdapter == null || mBluetoothGatt == null) {
            showToastNotification("Ocurrio un error al tratar de enviar el mensaje! No se ha podido establecer conexión con el dispositivo.");
            return;
        }
        //mBluetoothGatt.discoverServices();
        /*check if the service is available on the device*/
        BluetoothGattService mCustomService = mBluetoothGatt.getService(SERVICE_UUID);
        if(mCustomService == null){
            showToastNotification("Ocurrio un error al tratar de enviar el mensaje! No se pudo detectar el servicio al cual transmitir información.");
            return;
        }
        /*get the read characteristic from the service*/
        BluetoothGattCharacteristic mWriteCharacteristic = mCustomService.getCharacteristic(UUID.fromString("6E400002-B5A3-F393-E0A9-E50E24DCCA9E"));
        mWriteCharacteristic.setValue(value.getBytes());//(value,android.bluetooth.BluetoothGattCharacteristic.FORMAT_UINT8,0);
        if(mBluetoothGatt.writeCharacteristic(mWriteCharacteristic) == false){
            //Log.w(TAG, "Failed to write characteristic");
            showToastNotification("Ocurrio un error al tratar de enviar el mensaje!");
        }
    }

    public void showToastNotification(String message){
        Toast.makeText(context, message, Toast.LENGTH_LONG).show();
    }

}
