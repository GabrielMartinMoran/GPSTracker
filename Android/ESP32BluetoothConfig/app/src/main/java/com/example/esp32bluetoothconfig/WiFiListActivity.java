package com.example.esp32bluetoothconfig;

import android.content.Intent;
import android.os.Bundle;
import android.support.design.widget.FloatingActionButton;
import android.support.design.widget.Snackbar;
import android.support.v4.app.FragmentManager;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.ListView;
import android.widget.Toast;

public class WiFiListActivity extends AppCompatActivity implements AddNetworkDialog.AddNetworkDialogListener {

    private ListView NetworksList;
    private ArrayAdapter<String> adapter;
    private WiFiListFragment mWiFiListFragment;
    private Button addNetworkButton;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_wi_fi_list);
        //Para que las demas actividades puedan accederlo
        FragmentManager fragmentManager = getSupportFragmentManager();
        mWiFiListFragment = WiFiListFragment.newInstance(this);
        fragmentManager.beginTransaction().replace(R.id.container, mWiFiListFragment).commit();

        addNetworkButton = (Button) findViewById(R.id.addNetworkButton);
        addNetworkButton.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View view){
                openAddNetworkDialog();
            }
        });

    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Indata.;flate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.menu_list, menu);
        return true;
    }

    @Override
    public void applyTexts(String SSID, String password) {
        String response = GlobalObjectManager.bluetoothHelper.makeRequest("$ADD_WIFI$" + SSID + "," + password);
        Toast.makeText(getBaseContext(), response, Toast.LENGTH_LONG).show();
        if(response == "200"){
            mWiFiListFragment.addNetwork(SSID);
        }
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

    private void openAddNetworkDialog(){
        AddNetworkDialog addNetworkDialog = new AddNetworkDialog();
        addNetworkDialog.show(getSupportFragmentManager(), "Agregar red WiFi");
    }

}
