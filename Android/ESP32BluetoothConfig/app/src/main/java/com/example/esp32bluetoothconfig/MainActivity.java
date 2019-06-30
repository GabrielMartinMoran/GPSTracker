package com.example.esp32bluetoothconfig;

import android.Manifest;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.support.v4.app.ActivityCompat;
import android.support.v4.content.ContextCompat;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import java.io.IOException;

public class MainActivity extends AppCompatActivity{

    private static final int MY_PERMISSIONS_REQUEST_ACCESS_FINE_LOCATION = 0;
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

        // Here, thisActivity is the current activity
        if (ContextCompat.checkSelfPermission(this,
                Manifest.permission.ACCESS_FINE_LOCATION)
                != PackageManager.PERMISSION_GRANTED) {

            // Should we show an explanation?
            if (ActivityCompat.shouldShowRequestPermissionRationale(this,
                    Manifest.permission.ACCESS_FINE_LOCATION)) {

            } else {
                ActivityCompat.requestPermissions(this,
                        new String[]{Manifest.permission.ACCESS_FINE_LOCATION},
                        MY_PERMISSIONS_REQUEST_ACCESS_FINE_LOCATION);
            }
        }
    }

    public void openBLEDevicesListActivity() {
        Intent intent = new Intent(this, BluetoothListActivity.class);
        startActivity(intent);
    }

    public void openMapActivity(){
        Intent intent = new Intent(this, MapActivity.class);
        startActivity(intent);
    }

}
