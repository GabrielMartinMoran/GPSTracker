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
    gpsController = new GPSController(uartNumber);
    unsigned int metrosEntrePuntos = 10;
    gps = new GPS(gpsController, metrosEntrePuntos);

    btServer->setEndConfigurationCallback(endConfigurationCallback);
}

Orchestator::~Orchestator()
{
    delete serialController;
    delete sdManager;
    delete wifiConfiguration;
    delete bluetooth;
    delete btServer;
    delete wifiConnector;
    delete endConfigurationCallback;
    delete ioManager;
    delete gpsController;
    delete gps;
}

void Orchestator::startWiFiConnector(WiFiConnector *wifiConnector)
{
    wifiConnector->beginConnectionLoop();
}
void Orchestator::startBluetoothServer(BluetoothServer *btServer)
{
    btServer->start();
}

void Orchestator::sendAvailableData()
{
    if (wifiConnector->isConnected())
    {
        HTTPClient httpClient = HTTPClient("gpstrackerapi.herokuapp.com");
        httpClient.setContentType("application/json");
        std::string fileToSendData = ioManager->getFilenameToSend();
        if (fileToSendData != "")
        {
            std::string fileContent = ioManager->getFileContent(fileToSendData);
            serialController->println("Tratando de enviar el archivo: " + fileToSendData);
            std::string postBody = "{\"device\": \"" + std::string(DEVICE_NAME) + "\", \"data\": \"" + fileContent + "\"}";
            int statusCode = httpClient.post("/store-data", postBody.c_str());
            if (statusCode == HTTP_CODE_OK)
            {
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
}

void Orchestator::start()
{
    serialController->println("Orchestator Start");

    /* ~~~  BLUETOOTH SERVER  ~~~ */
    
    std::thread bluetoothServerThread = std::thread(Orchestator::startBluetoothServer, btServer);

    while (!endConfigurationCallback->configurationEnded)
    {
        delay(200);
    }

    btServer->stop();
    
    serialController->println("Finalizo el Bluetooth");
    bluetoothServerThread.join();
    
    /* ~~~~~~~~~~~~~~~~~~~~~~~~~~ */

    serialController->println("Iniciando captura de datos GPS");

    /* ~~~  CONEXION WiFi  ~~~ */
    std::thread *wifiConnectorThread = new std::thread(Orchestator::startWiFiConnector, wifiConnector);
    /* ~~~~~~~~~~~~~~~~~~~~~~~ */
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
        //Envio de datos por HTTP
        this->sendAvailableData();
        if (actualizado != actualizado_aux)
        {
            actualizado_aux = actualizado;
            actualizado ? serialController->println("actualizado") : serialController->println("no actualizado");
            //Serial.print("HEAP DISPONIBLE: ");
            //Serial.println((unsigned long)ESP.getFreeHeap());
            
        }
        else
        {
            delay(500);
        }
    }
    wifiConnectorThread->join();
    delete wifiConnectorThread;
    
}