#include <Arduino.h>
#include <Bluetooth.h>
#include <WiFiConnector.h>

void setup()
{
    Serial.begin(115200);    

    WifiConnector *wifi = new WifiConnector();

    wifi->getAvaliableNetworks();

    wifi->connect("Fibertel WiFi589 2.4GHz", "00438829825");

    Bluetooth *bt = new Bluetooth();

    delete wifi;
    delete bt;

}

void loop()
{
}