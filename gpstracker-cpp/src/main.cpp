#include <Arduino.h>
#include <BluetoothServer.h>
#include <WiFiConfiguration.h>

void setup()
{
    Serial.begin(115200);

    WiFiConfiguration *wifiConfiguration = new WiFiConfiguration();

    BluetoothServer *btServer = new BluetoothServer(wifiConfiguration);

    //delete bt;
    Serial.println("~~ Fin del setup ~~");
}

void loop()
{
}