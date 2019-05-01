package com.example.esp32bluetoothconfig;

import android.app.Activity;
import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.content.Intent;
import android.support.v4.app.FragmentManager;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.ArrayAdapter;
import android.widget.ListView;

import java.util.ArrayList;
import java.util.List;
import java.util.Set;

import static android.support.v4.app.ActivityCompat.startActivityForResult;

public class BluetoothListActivity extends AppCompatActivity implements DeviceListFragment.OnFragmentInteractionListener {

    private ListView BLEdevicesList;
    private ArrayAdapter<String> adapter;
    private BluetoothHelper btHelper;
    private DeviceListFragment mDeviceListFragment;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_bluetooth_list);
        btHelper = new BluetoothHelper(getBaseContext());
        //Para que las demas actividades puedan accederlo
        GlobalObjectManager.bluetoothHelper = btHelper;
        connectBluetooth();
        FragmentManager fragmentManager = getSupportFragmentManager();

        mDeviceListFragment = DeviceListFragment.newInstance(btHelper, this);
        fragmentManager.beginTransaction().replace(R.id.container, mDeviceListFragment).commit();
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Indata.;flate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.menu_list, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();


        //noinspection SimplifiableIfStatement
        if (id == R.id.action_settings) {
            return true;
        }

        return super.onOptionsItemSelected(item);
    }

    @Override
    public void onFragmentInteraction(String id) {

    }

    //Se encuentra aca este metodo ya que startActivityForResult solo puede llamarse dentro de una activity
    private void connectBluetooth(){
        if (!btHelper.getAdapter().isEnabled()) {
            Intent enableBT = new Intent(BluetoothAdapter.ACTION_REQUEST_ENABLE);
            startActivityForResult(enableBT, BluetoothHelper.REQUEST_BLUETOOTH);
        }
    }

    private void OnDeviceConnected(){
        finish();
    }
}
