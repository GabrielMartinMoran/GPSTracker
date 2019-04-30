#include <Arduino.h>
#include <Bluetooth.h>
#include <WiFiConnector.h>
#include <WiFiConfiguration.h>
#include <SDManager.h>

void setup()
{
    Serial.begin(115200);
    
    WiFiConnector *wifi = new WiFiConnector();
    
    //Esperamos para que se inicialize el WiFi
    delay(2000);
    /*
    Serial.print("RED DISPONIBLE: ");
    Serial.print(wifi->isNetworkAvaliable("Fibertel WiFi589 2.4GHz"));
    Serial.println();
    //wifi->getAvaliableNetworks();

    Bluetooth *bt = new Bluetooth();

    //wifi->connect("Fibertel WiFi589 2.4GHz", "00438829825");

    delete bt;
    */

    Serial.println("Iniciando...");

    SDManager *sdManager = new SDManager();

    sdManager->isValidSD();

    WiFiConfiguration *wifiConfig = new WiFiConfiguration();
    wifiConfig->loadConfiguration();
    wifiConfig->printConfiguratedNetworks();

    WiFiNetwork *networkToConnect = wifiConfig->getNetworkAtPosition(0);
    Serial.println(networkToConnect->toString());

    Serial.print("Is "+ networkToConnect->SSID + " network avaliable: ");
    Serial.println(wifi->isNetworkAvaliable(networkToConnect->SSID));

    wifi->connect(networkToConnect->SSID, networkToConnect->password);

    //wifi->connect("Fibertel WiFi589 2.4GHz", "00438829825");

    delete sdManager;
    delete wifiConfig;
    delete wifi;

    Serial.println("~~ Fin del setup ~~");
}

void loop()
{
}