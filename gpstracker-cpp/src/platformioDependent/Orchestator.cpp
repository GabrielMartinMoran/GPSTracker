#include <platformioDependent/Orchestator.h>

Orchestator::Orchestator()
{
    
    serialController = new SerialController();
    sdManager = new SDManager();
    wifiConfiguration = new WiFiConfiguration(sdManager);
    bluetooth = new Bluetooth();
    btServer = new BluetoothServer(wifiConfiguration, bluetooth, serialController);
    wifiConnector = new WiFiConnector(wifiConfiguration);
    endConfigurationCallback = new EndConfigurationCallback();

    btServer->setEndConfigurationCallback(endConfigurationCallback);

    //------- PARA TESTEAR CONFIGURAMOS ACA LAS REDES WIFI --------
    size_t configuredNetowrks = wifiConfiguration->getConfiguredNetworks();
    serialController->print("CANTIDAD DE REDES WIFI CONFIGURADAS: ");
    serialController->println(configuredNetowrks);
    if (configuredNetowrks == 0)
    {
        serialController->println("Configurando redes WiFi por defecto...");
        wifiConfiguration->addNetwork("ABC", "123");
        wifiConfiguration->addNetwork("DEF", "456");
        wifiConfiguration->addNetwork("GHI", "789");
        wifiConfiguration->addNetwork("Gabriel", "pass1234");
    }
    //-------------------------------------------------------------
    
}

Orchestator::~Orchestator()
{
}

void Orchestator::startWiFiConnector()
{
}
void Orchestator::startBluetoothServer(BluetoothServer *btServer)
{
    btServer->start();
}
void Orchestator::startNetworkDataSender()
{
}
void Orchestator::startGPSDataProvider()
{
}

void Orchestator::start()
{
    serialController->println("Orchestator Start");
    std::thread bluetoothServerThread = std::thread(Orchestator::startBluetoothServer, btServer);
    while(endConfigurationCallback->configurationEnded == false){
        delay(200);
    }
    btServer->stop();
    serialController->println("Finalizo el Bluetooth");
    bluetoothServerThread.join();
    serialController->println("Iniciando el WiFi");
    wifiConnector->beginConnectionLoop();
}