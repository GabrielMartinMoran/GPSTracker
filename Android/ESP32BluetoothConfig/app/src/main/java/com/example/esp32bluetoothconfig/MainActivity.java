package com.example.esp32bluetoothconfig;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import java.io.IOException;

public class MainActivity extends AppCompatActivity{

    Button openBLEListActivityBtn;
    Button openMap;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        //evaluateBLECompatibility();

        openBLEListActivityBtn = (Button) findViewById(R.id.openBLEListActivityBtn);
        openBLEListActivityBtn.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v) {
                openBLEDevicesListActivity();
            }
        });

        openMap = (Button) findViewById(R.id.openMap);
        openMap.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v) {
                openMapActivity();
            }
        });
    }

    /*private void evaluateBLECompatibility() {
        // Use this check to determine whether BLE is supported on the device. Then
        // res.
        if (!getPackageManager().hasSystemFeature(PackageManager.FEATURE_BLUETOOTH_LE)) {
            Toast.makeText(this, R.string.ble_not_supported, Toast.LENGTH_SHORT).show();
            finish();
        }
    }*/

    public void openBLEDevicesListActivity() {
        Intent intent = new Intent(this, BluetoothListActivity.class);
        startActivity(intent);
    }

    public void openMapActivity(){
        Intent intent = new Intent(this, MapActivity.class);
        startActivity(intent);
    }

}
