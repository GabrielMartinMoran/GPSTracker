package com.example.esp32bluetoothconfig;

import android.content.Intent;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

public class DeviceConnectedActivity extends AppCompatActivity {


    TextView connectedDeviceTextView;
    Button openWiFiListActivityBtn;
    Button endConfiguration;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_device_connected);

        openWiFiListActivityBtn = findViewById(R.id.openWiFiListActivityBtn);
        openWiFiListActivityBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                openWiFiListListActivity();
            }
        });

        endConfiguration = findViewById(R.id.endConfigurationBtn);
        endConfiguration.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                endConfiguration();
            }
        });

        connectedDeviceTextView = findViewById(R.id.connectedDeviceTextView);
        connectedDeviceTextView.setText(GlobalObjectManager.bluetoothHelper.connectedDeviceName);
    }

    public void openWiFiListListActivity() {
        Intent intent = new Intent(this, WiFiListActivity.class);
        startActivity(intent);
    }

    public void endConfiguration() {
        String received = GlobalObjectManager.bluetoothHelper.makeRequest("$END_CONFIGURATION$");
        if (received == null) {
            received = "";
        }
        Log.d("RESPONSE", received);
        Toast.makeText(this, received,
                Toast.LENGTH_LONG).show();
        if(received.equals("200")){
            Intent intent = new Intent(this, MainActivity.class);
            intent.addFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP);
            startActivity(intent);
        }
    }


}
