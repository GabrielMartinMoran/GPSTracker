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
    unsigned int metrosEntrePuntos = 2;
    this->gps = new GPS(gpsController, metrosEntrePuntos);

    btServer->setEndConfigurationCallback(endConfigurationCallback);

    //------- PARA TESTEAR CONFIGURAMOS ACA LAS REDES WIFI --------
    /*
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
    */
    //-------------------------------------------------------------
}

Orchestator::~Orchestator()
{
}

void Orchestator::startWiFiConnector(WiFiConnector *wifiConnector)
{
    wifiConnector->beginConnectionLoop();
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
            std::string line = gps->getGPSData().getNormalizedData();
            ioManager->write(line);
        }
        else
        {
            delay(500);
        }
        if (actualizado != actualizado_aux)
        {
            actualizado ? serialController->println("actualizado") : serialController->println("no actualizado");
        }
    }
}

void Orchestator::start()
{
    serialController->println("Orchestator Start");
    
    std::thread bluetoothServerThread = std::thread(Orchestator::startBluetoothServer, btServer);
    
    /*
    while (endConfigurationCallback->configurationEnded == false)
    {
        delay(200);
    }
    */
    btServer->stop();
    serialController->println("Finalizo el Bluetooth");
    bluetoothServerThread.join();
    
    //wifiConnector->beginConnectionLoop();
    
    serialController->println("Iniciando captura de datos GPS");
    //std::thread *GPSThread = new std::thread(Orchestator::startGPSDataProvider, ioManager, gps, serialController);
    //GPSThread->join();
    //delete GPSThread;
    //serialController->println("Iniciando el WiFi");
    //std::thread *wifiConnectorThread = new std::thread(Orchestator::startWiFiConnector, wifiConnector);
    bool actualizado_aux = false;
    bool actualizado = false;

    //HTTPClient client = HTTPClient("gpstrackerapi.herokuapp.com");
    //std::string *postBody = new std::string("{\"device\": \"ESP32_GPSTracker\", \"data\": \"19-05-28 00:34:51,-034.56571,-058.53415\\n19-05-28 00:34:51,-034.56607,-058.53430\\n19-05-28 00:34:51,-034.56633,-058.53437\\n19-05-28 00:34:51,-034.56656,-058.53411\\n19-05-28 00:34:51,-034.56685,-058.53374\\n19-05-28 00:34:51,-034.56707,-058.53347\\n19-05-28 00:34:51,-034.56725,-058.53323\\n19-05-28 00:34:51,-034.56762,-058.53280\\n19-05-28 00:34:51,-034.56804,-058.53231\\n19-05-28 00:34:51,-034.56830,-058.53239\\n19-05-28 00:34:51,-034.56858,-058.53270\\n19-05-28 00:34:51,-034.56879,-058.53297\\n19-05-28 00:34:51,-034.56915,-058.53334\\n19-05-28 00:34:51,-034.56943,-058.53369\\n19-05-28 00:34:51,-034.56967,-058.53400\\n19-05-28 00:34:51,-034.56995,-058.53431\\n19-05-28 00:34:51,-034.57021,-058.53464\\n19-05-28 00:34:51,-034.57062,-058.53515\\n19-05-28 00:34:51,-034.57105,-058.53565\\n19-05-28 00:34:51,-034.57137,-058.53603\\n19-05-28 00:34:51,-034.57168,-058.53643\\n19-05-28 00:34:51,-034.57197,-058.53678\\n19-05-28 00:34:51,-034.57237,-058.53623\\n19-05-28 00:34:51,-034.57282,-058.53575\\n19-05-28 00:34:51,-034.57321,-058.53515\\n19-05-28 00:34:51,-034.57365,-058.53469\\n19-05-28 00:34:51,-034.57402,-058.53422\\n19-05-28 00:34:51,-034.57454,-058.53367\\n19-05-28 00:34:51,-034.57483,-058.53399\\n19-05-28 00:34:51,-034.57517,-058.53438\\n19-05-28 00:34:51,-034.57560,-058.53486\\n19-05-28 00:34:51,-034.57607,-058.53541\\n19-05-28 00:34:51,-034.57645,-058.53582\\n19-05-28 00:34:51,-034.57683,-058.53627\\n19-05-28 00:34:51,-034.57723,-058.53679\\n\"}");
    while (true)
    {
        /*
        if(false){
            client.setContentType("application/json");
            //int statusCode = client.post("/store-data", postBody->c_str());
            serialController->print(millis()/1000);
            serialController->print(" Response status code: ");
            //serialController->println(statusCode);
        */
        actualizado = gps->actualizado();
        if (actualizado)
        {
            std::string line = gps->getGPSData().getNormalizedData();
            ioManager->write(line);
        }/*
        if (wifiConnector->isConnected())
        {
            
            if (false)
            {
                String response;
                //int statusCode = client.get("/", &response);
                std::string postBody = "{\"device\": \"ESP32_GPSTracker\", \"data\": \"" + ioManager->read() + "\"}";
                int statusCode = client.post("/store-data", postBody.c_str(), &response);
                serialController->print("Status code: ");
                serialController->println(statusCode);
                serialController->print("Response: ");
                serialController->println(std::string(response.c_str()));
            }
        }*/
        if(actualizado != actualizado_aux){
            actualizado_aux = actualizado;
            actualizado ? serialController->println("actualizado") : serialController->println("no actualizado");
        }
        else
        {
            delay(500);
        }
    }
    //delete postBody;
    //wifiConnectorThread->join();
}