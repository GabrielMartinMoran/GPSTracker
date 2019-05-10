#include <Orchestator.h>

Orchestator::Orchestator()
{
    /*
    serialController = new SerialController();
    sdManager = new SDManager();
    wifiConfiguration = new WiFiConfiguration(sdManager);
    bluetooth = new Bluetooth();
    btServer = new BluetoothServer(wifiConfiguration, bluetooth, serialController);
    wifiConnector = new WiFiConnector(wifiConfiguration);

    //------- PARA TESTEAR CONFIGURAMOS ACA LAS REDES WIFI --------
    if (wifiConfiguration->getConfiguredNetworks() == 0)
    {
        Serial.println("Configurando redes WiFi por defecto...");
        wifiConfiguration->addNetwork("ABC", "123");
        wifiConfiguration->addNetwork("DEF", "456");
        wifiConfiguration->addNetwork("GHI", "789");
        wifiConfiguration->addNetwork("Gabriel", "pass1234");
    }
    //-------------------------------------------------------------
    */
}

Orchestator::~Orchestator()
{
}

void Orchestator::startWiFiConnector()
{
}
void Orchestator::startBluetoothServer()
{
}
void Orchestator::startNetworkDataSender()
{
}
void Orchestator::startGPSDataProvider()
{
}

void Orchestator::start()
{
}