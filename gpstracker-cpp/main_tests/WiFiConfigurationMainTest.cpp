#include <Arduino.h>
#include <Bluetooth.h>
#include <WiFiConnector.h>
#include <WiFiConfiguration.h>
#include <SDManager.h>

void setup()
{
    Serial.begin(115200);

    //WiFiConnector *wifi = new WiFiConnector();

    //Esperamos para que se inicialize el WiFi
    //delay(2000);
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

    WiFiConfiguration *wifiConfig = new WiFiConfiguration();

    pinMode(LED_BUILTIN, OUTPUT);
    delay(2000);
    if (touchRead(T4) < 50)
    {
        digitalWrite(LED_BUILTIN, HIGH);
        Serial.println("Borrando archivo de configuracion de wifi");
        wifiConfig->deleteConfigurationFile();
        delay(1000);
        digitalWrite(LED_BUILTIN, LOW);
        return;
    }

    Serial.println("Redes configuradas luego de la inicialmente:");
    wifiConfig->printConfiguratedNetworks();

    if (wifiConfig->getConfiguredNetworks() == 0)
    {
        wifiConfig->addNetwork("ABC", "123");
        wifiConfig->addNetwork("DEF", "456");
        wifiConfig->addNetwork("GHI", "789");
    }
    wifiConfig->addNetwork("WiFi_to_delete", "123456");

    Serial.println("\n\nRedes configuradas luego de la insercion:");
    wifiConfig->printConfiguratedNetworks();

    for (size_t i = 0; i < wifiConfig->getConfiguredNetworks(); i++)
    {
        if (wifiConfig->getNetworkAtPosition(i)->SSID == "WiFi_to_delete")
        {
            wifiConfig->removeNetwork(i);
            break;
        }
    }

    Serial.println("\n\nRedes configuradas luego de la eliminacion de WiFi_to_delete:");
    wifiConfig->printConfiguratedNetworks();

    //WiFiNetwork *networkToConnect = wifiConfig->getNetworkAtPosition(0);
    //wifi->connect(networkToConnect->SSID, networkToConnect->password);

    delete wifiConfig;
    //delete wifi;

    Serial.println("~~ Fin del setup ~~");
}

void loop()
{
}