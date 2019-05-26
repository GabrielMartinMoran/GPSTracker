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
    Button openWiFiListActivityBtn;
    Button sendButton;
    Button endConfiguration;
    Button openMap;
    EditText textInput;

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

        openWiFiListActivityBtn = (Button) findViewById(R.id.openWiFiListActivityBtn);
        openWiFiListActivityBtn.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v) {
                openWiFiListListActivity();
            }
        });

        sendButton = (Button) findViewById(R.id.sendButton);
        sendButton.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v) {
                sendData();
            }
        });

        endConfiguration = (Button) findViewById(R.id.endConfigurationBtn);
        endConfiguration.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v) {
                endConfiguration();
            }
        });

        openMap = (Button) findViewById(R.id.openMap);
        openMap.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v) {
                openMapActivity();
            }
        });

        textInput = (EditText) findViewById(R.id.textInput);
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

    public void openWiFiListListActivity() {
        Intent intent = new Intent(this, WiFiListActivity.class);
        startActivity(intent);
    }

    public void sendData() {
        String text = textInput.getText().toString();
        String received = GlobalObjectManager.bluetoothHelper.makeRequest(text);
        if(received == null){
            received = "";
        }
        Log.d("RESPONSE", received);
        Toast.makeText(this, received,
                Toast.LENGTH_LONG).show();
    }

    public void endConfiguration() {
        String received = GlobalObjectManager.bluetoothHelper.makeRequest("$END_CONFIGURATION$");
        if(received == null){
            received = "";
        }
        Log.d("RESPONSE", received);
        Toast.makeText(this, received,
                Toast.LENGTH_LONG).show();
    }

    public void openMapActivity(){
        Intent intent = new Intent(this, MapActivity.class);
        startActivity(intent);
    }

}
