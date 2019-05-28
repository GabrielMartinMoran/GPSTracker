#include <platformioDependent/Orchestator.h>

Orchestator::Orchestator()
{
    serialController = new SerialController();
    uint8_t ssPin = 5;
    sdManager = new SDManager(ssPin);
    wifiConfiguration = new WiFiConfiguration(sdManager);
    bluetooth = new Bluetooth();
    btServer = new BluetoothServer(wifiConfiguration, bluetooth, serialController);
    wifiConnector = new WiFiConnector(wifiConfiguration);
    endConfigurationCallback = new EndConfigurationCallback();
    ioManager = new IOManager(sdManager);
    int uartNumber = 2;
    GPSController *gpsController = new GPSController(uartNumber);
    this->gps = new GPS(gpsController);

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
        wifiConfiguration->addNetwork("Gabriel-Notebook AP", "Passw0rd");
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
void Orchestator::startGPSDataProvider(IOManager *ioManager, GPS *gps, SerialController *serialController)
{
    bool actualizado_aux = false;
    bool actualizado = false;
    while (true)
    {
        actualizado = gps->actualizado();
        if (actualizado)
        {
            std::string *line = new std::string(gps->getGPSData().getNormalizedData());
            ioManager->write(line);
            delete line;
        }
        else
        {
            delay(500);
        }
        if(actualizado != actualizado_aux){
            actualizado ? serialController->println("actualizado") : serialController->println("no actualizado");
        }
    }
}

void Orchestator::start()
{
    //serialController->println("Orchestator Start");
    /*
    std::thread bluetoothServerThread = std::thread(Orchestator::startBluetoothServer, btServer);
    while (endConfigurationCallback->configurationEnded == false)
    {
        delay(200);
    }
    btServer->stop();
    serialController->println("Finalizo el Bluetooth");
    bluetoothServerThread.join();
    serialController->println("Iniciando el WiFi");
    wifiConnector->beginConnectionLoop();
    */
    serialController->println("Iniciando captura de datos GPS");
    //std::thread *GPSThread = new std::thread(Orchestator::startGPSDataProvider, ioManager, gps, serialController);
    //GPSThread->join();
    //delete GPSThread;
    bool actualizado_aux = false;
    bool actualizado = false;
    while (true)
    {
        actualizado = gps->actualizado();
        if (actualizado)
        {
            std::string *line = new std::string(gps->getGPSData().getNormalizedData());
            ioManager->write(line);
            delete line;
        }
        else
        {
            delay(500);
        }
        if(actualizado != actualizado_aux){
            actualizado ? serialController->println("actualizado") : serialController->println("no actualizado");
        }
    }
}