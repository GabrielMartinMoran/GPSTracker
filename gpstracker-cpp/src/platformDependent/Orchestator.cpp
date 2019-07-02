#include <platformDependent/Orchestator.h>

Orchestator::Orchestator()
{   
    serialController = new SerialController();
    sdManager = new SDManager(SD_CARD_PIN);
    wifiConfiguration = new WiFiConfiguration(sdManager);
    bluetooth = new Bluetooth();
    btServer = new BluetoothServer(wifiConfiguration, bluetooth, serialController);
    wifiConnector = new WiFiConnector(wifiConfiguration);
    endConfigurationCallback = new EndConfigurationCallback();
    ioManager = new IOManager(sdManager, wifiConnector);
    gpsController = new GPSController(GPS_UART_NUMBER);
    gps = new GPS(gpsController, METERS_BETWEEN_POINTS);

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

void *Orchestator::startWiFiConnector(void *wifiConnector)
{
    (static_cast<WiFiConnector *>(wifiConnector))->beginConnectionLoop();
    return NULL;
}

void *Orchestator::startBluetoothServer(void *btServer)
{
    (static_cast<BluetoothServer *>(btServer))->start();
    return NULL;
}

void Orchestator::sendAvailableData()
{
    if (wifiConnector->isConnected())
    {
        HTTPClient httpClient = HTTPClient("gpstrackerapi.herokuapp.com");
        std::string fileToSendData = ioManager->getFilenameToSend();
        if (fileToSendData != "")
        {
            std::string fileContent = ioManager->getFileContent(fileToSendData);
            serialController->println("Tratando de enviar el archivo: " + fileToSendData);
            std::string postBody = "{\"device\": \"" + std::string(DEVICE_NAME) + "\", \"data\": \"" + fileContent + "\"}";
            int statusCode = httpClient.post("/store-data", postBody);
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

void Orchestator::startBluetoothConfiguration()
{
    pthread_attr_t threadConfig;
    pthread_attr_init(&threadConfig);
    pthread_attr_setstacksize(&threadConfig, BLUETOOTH_SERVER_THREAD_STACK_SIZE);
    pthread_t bluetoothServerThread;
    pthread_create(&bluetoothServerThread, &threadConfig, &Orchestator::startBluetoothServer, (void *)btServer);

    while (!endConfigurationCallback->configurationDone())
    {
        delay(200);
        endConfigurationCallback->increaseTimer(200);
    }

    // Para poder terminarlo desde afuera
    pthread_cancel(bluetoothServerThread);
    btServer->stop();
    serialController->println("La configuracion Bluetooth ha finalizado");
    char *btServerRet;
    pthread_join(bluetoothServerThread, (void **)&btServerRet);
}

void Orchestator::start()
{
    serialController->println("Orchestator Start");
    LedBlinker::blink(4, 100, 100);

    /* ~~~  BLUETOOTH SERVER  ~~~ */
    this->startBluetoothConfiguration();
    /* ~~~~~~~~~~~~~~~~~~~~~~~~~~ */
    LedBlinker::blink(2, 500, 500);
    /* ~~~  CONEXION WiFi  ~~~ */
    pthread_attr_t threadConfig;
    pthread_attr_init(&threadConfig);
    pthread_attr_setstacksize(&threadConfig, WIFI_CONNECTOR_THREAD_STACK_SIZE);
    pthread_t wifiConnectorThread;
    pthread_create(&wifiConnectorThread, &threadConfig, &Orchestator::startWiFiConnector, (void *)wifiConnector);
    /* ~~~~~~~~~~~~~~~~~~~~~~~ */

    serialController->println("Iniciando la captura de datos del GPS");

    while (true)
    {
        if (gps->updated())
        {
            std::string line = gps->getGPSData()->getNormalizedData();
            ioManager->write(line);
        }
        //Envio de datos por HTTP
        this->sendAvailableData();

        delay(500);
    }
    pthread_cancel(wifiConnectorThread);
}