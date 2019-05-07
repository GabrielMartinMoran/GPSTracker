#include <BluetoothServer.h>

BluetoothServer::BluetoothServer(IWiFiConfiguration *wifiConfiguration, IBluetooth *bluetooth)
{
    this->wifiConfiguration = wifiConfiguration;
    bt = bluetooth;
    bt->configureWriteCallback(this);
}

BluetoothServer::~BluetoothServer()
{
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
    if (request.length() > 0)
    {
        //Definimos los comandos validos
        const std::string DELETE_WIFI = "$DELETE_WIFI$";
        const std::string TURN_LED_ON = "A";         //"$TURN_LED_ON$";
        const std::string TURN_LED_OFF = "B";        //"$TURN_LED_OFF$";
        const std::string LIST_WIFI = "$LIST_WIFI$";
        const std::string ADD_WIFI = "$ADD_WIFI$";
        //------------------------------

        if (request == "A")
        {
            //digitalWrite(LED_BUILTIN, HIGH);
            sendResponse(OK);
            return;
        }
        if (request == "B")
        {
            //digitalWrite(LED_BUILTIN, LOW);
            sendResponse(OK);
            return;
        }
        if (isCommand(request, DELETE_WIFI))
        {
            std::string networkToDelete = getData(request, DELETE_WIFI);
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
        if (isCommand(request, LIST_WIFI))
        {
            sendResponse(wifiConfiguration->listNetworks());
            return;
        }
        if(isCommand(request, ADD_WIFI)){
            bool networkAdded = wifiConfiguration->addNetworkFromCSVLine(getData(request, ADD_WIFI));
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
        //Serial.println("Unrecognized Bluetooth request: " + String(request.c_str()));
        sendResponse(ERROR);
    }
}

void BluetoothServer::sendResponse(std::string response)
{
    bt->transmitData(response);
}