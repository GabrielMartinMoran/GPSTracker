package com.example.esp32bluetoothconfig;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.webkit.WebView;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import java.io.IOException;

public class MapActivity extends AppCompatActivity{

    WebView webView;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_map);

        webView = (WebView) findViewById(R.id.webView);

        openMap();
    }

    public void openMap(){
        String html = "<iframe width=\"800\" height=\"600\" src=\"https://app.powerbi.com/view?r=eyJrIjoiODQ3ZjllMmQtYzcyZS00ZGJjLTgyYzAtYTMyYjE1NDBhNTUzIiwidCI6Ijc1NzgzNjllLWNmNjEtNDQ0MC05YTkyLThjOGM2ZTU0YmY3MSIsImMiOjR9\" frameborder=\"0\" allowFullScreen=\"true\"></iframe>";
        webView.loadData(html, "text/html", null);
    }


}
