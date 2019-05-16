#include <BluetoothServer.h>

BluetoothServer::BluetoothServer(IWiFiConfiguration *wifiConfiguration, IBluetooth *bluetooth, ISerialController *serialController)
{
    this->wifiConfiguration = wifiConfiguration;
    this->bluetooth = bluetooth;
    this->serialController = serialController;
    //bluetooth->configureWriteCallback(this);
}

BluetoothServer::~BluetoothServer()
{
}

void BluetoothServer::start()
{
    bluetooth->start(this);
}

void BluetoothServer::stop()
{
    bluetooth->stop();
}

bool BluetoothServer::isCommand(std::string request, std::string command)
{
    if (command.length() > request.length())
    {
        return false;
    }
    return command == request || command == request.substr(0, command.length());
}

std::string BluetoothServer::getData(std::string request, std::string command)
{
    if (command.length() >= request.length())
    {
        return "";
    }
    return request.substr(command.length());
}

void BluetoothServer::onRequest(std::string request)
{
    serialController->println("REQUEST: " + std::string(request.c_str()));
    if (request.length() > 0)
    {
        if (request == TURN_LED_ON)
        {
            //digitalWrite(LED_BUILTIN, HIGH); //Comentado porque sino habria que importar Arduino.h y romperia los tests
            sendResponse(OK);
            return;
        }
        if (request == TURN_LED_OFF)
        {
            //digitalWrite(LED_BUILTIN, LOW); //Comentado porque sino habria que importar Arduino.h y romperia los tests
            sendResponse(OK);
            return;
        }
        if (isCommand(request, DELETE_NETWORK))
        {
            std::string networkToDelete = getData(request, DELETE_NETWORK);
            bool deleted = wifiConfiguration->deleteNetwork(networkToDelete);
            if (deleted)
            {
                sendResponse(OK);
            }
            else
            {
                sendResponse(ERROR);
            }
            return;
        }
        if (isCommand(request, LIST_NETWORKS))
        {
            sendResponse(wifiConfiguration->listNetworks());
            return;
        }
        if (isCommand(request, ADD_NETWORK))
        {
            bool networkAdded = wifiConfiguration->addNetworkFromCSVLine(getData(request, ADD_NETWORK));
            if (networkAdded)
            {
                sendResponse(OK);
            }
            else
            {
                sendResponse(ERROR);
            }
            return;
        }
        if (request == END_CONFIGURATION)
        {
            sendResponse(OK);
            return;
        }
        //Comentado porque sino habria que importar Arduino.h y romperia los tests
        //Igualmente habria que utilizar el SerialController en todo caso
        //Serial.println("Unrecognized Bluetooth request: " + String(request.c_str()));
        serialController->println("Unrecognized Bluetooth request: " + std::string(request.c_str()));
        sendResponse(ERROR);
    }
}

void BluetoothServer::sendResponse(std::string response)
{
    bluetooth->transmitData(response);
}