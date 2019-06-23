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
    ioManager = new IOManager(sdManager, wifiConnector);
    int uartNumber = 2;
    GPSController *gpsController = new GPSController(uartNumber);
    unsigned int metrosEntrePuntos = 0;
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
            std::string line = gps->getGPSData()->getNormalizedData();
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


    /* ~~~  BLUETOOTH SERVER  ~~~ */
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
    /* ~~~~~~~~~~~~~~~~~~~~~~~~~~ */

    serialController->println("Iniciando captura de datos GPS");
    //std::thread *GPSThread = new std::thread(Orchestator::startGPSDataProvider, ioManager, gps, serialController);
    //GPSThread->join();
    //delete GPSThread;
    //serialController->println("Iniciando el WiFi");

    /* ~~~  CONEXION WiFi  ~~~ */
    std::thread *wifiConnectorThread = new std::thread(Orchestator::startWiFiConnector, wifiConnector);
    /* ~~~~~~~~~~~~~~~~~~~~~~~ */
    bool actualizado_aux = false;
    bool actualizado = false;

    /*
    //Para tests
    int seconds = -1;
    int minutes = 0;
    int hours = 0;
    //----------
    */
    HTTPClient httpClient = HTTPClient("gpstrackerapi.herokuapp.com");
    httpClient.setContentType("application/json");

    while (true)
    {
        actualizado = gps->actualizado();
        //actualizado = true; //Solo para pruebas
        if (actualizado)
        {
            std::string line = gps->getGPSData()->getNormalizedData();
            /*
            //Para pruebas
            seconds ++;
            if(seconds == 60){
                seconds = 0;
                minutes ++;
                if(minutes == 60){
                    minutes = 0;
                    hours ++;
                }
            }
            char datetime[18];
            sprintf(datetime, "%s %02d:%02d:%02d", "19-05-18", hours, minutes, seconds);
            std::string line = ",-034.61005,-058.55567,0\n";
            line.insert(0, datetime);
            //-----------
            */
            ioManager->write(line);
        }
        //Envio de datos por HTTP
        if (wifiConnector->isConnected())
        {
            std::string fileToSendData = ioManager->getFilenameToSend();
            if (fileToSendData != "")
            {
                std::string fileContent = ioManager->getFileContent(fileToSendData);
                serialController->println("Tratando de enviar el archivo: " + fileToSendData);
                std::string postBody = "{\"device\": \"" + std::string(DEVICE_NAME) + "\", \"data\": \"" + fileContent + "\"}";
                int statusCode = httpClient.post("/store-data", postBody.c_str());
                if(statusCode == HTTP_CODE_OK){
                    ioManager->deleteFile(fileToSendData);
                }
                serialController->print("Response status code: ");
                serialController->println(statusCode);
            }
            else
            {
                serialController->println("Nada para enviar");
            }
        }
        if (actualizado != actualizado_aux)
        {
            actualizado_aux = actualizado;
            actualizado ? serialController->println("actualizado") : serialController->println("no actualizado");
            Serial.println((unsigned long)ESP.getFreeHeap());
        }
        else
        {
            delay(500);
        }
    }
    //delete postBody;
    //wifiConnectorThread->join();
}