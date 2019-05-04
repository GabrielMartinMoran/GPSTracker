#include <BluetoothServer.h>

BluetoothServer::BluetoothServer(WiFiConfiguration *wifiConfiguration)
{
    this->wifiConfiguration = wifiConfiguration;
    bt = new Bluetooth();
    bt->configureWriteCallback(this);
}

BluetoothServer::~BluetoothServer()
{
    delete bt;
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
            digitalWrite(LED_BUILTIN, HIGH);
            sendResponse(OK);
            return;
        }
        if (request == "B")
        {
            digitalWrite(LED_BUILTIN, LOW);
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
        Serial.println("Unrecognized Bluetooth request: " + String(request.c_str()));
        sendResponse(ERROR);
        /*
        Serial.println("*********");
        Serial.print("Received Value: ");

        for (int i = 0; i < request.length(); i++)
        {
            Serial.print(request[i]);
        }

        Serial.println();

        // Do stuff based on the command received from the app
        if (request == "A")
        {
            Serial.print("Turning ON!");
            digitalWrite(LED_BUILTIN, HIGH);
            sendResponse("Turning ON!");
        }
        else if (request == "B")
        {
            Serial.print("Turning OFF!");
            digitalWrite(LED_BUILTIN, LOW);
            sendResponse("Turning OFF!");
        }
        else if (request.substring())
            else
            {
                Serial.print("Command not recognized!");
            }

        Serial.println();
        Serial.println("*********");
        */
    }
}

void BluetoothServer::sendResponse(std::string response)
{
    bt->transmitData(response);
}