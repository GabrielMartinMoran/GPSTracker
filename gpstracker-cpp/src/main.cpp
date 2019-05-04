#include <Arduino.h>
#include <BluetoothServer.h>
#include <WiFiConfiguration.h>

void setup()
{
    Serial.begin(115200);

    WiFiConfiguration *wifiConfiguration = new WiFiConfiguration();
    if (wifiConfiguration->getConfiguredNetworks() == 0)
    {
        wifiConfiguration->addNetwork("ABC", "123");
        wifiConfiguration->addNetwork("DEF", "456");
        wifiConfiguration->addNetwork("GHI", "789");
    }

    BluetoothServer *btServer = new BluetoothServer(wifiConfiguration);

    //delete bt;
    Serial.println("~~ Fin del setup ~~");
}

void loop()
{
}