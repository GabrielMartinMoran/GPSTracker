#include <BluetoothServer.h>

BluetoothServer::BluetoothServer()
{
    bt = new Bluetooth();
    bt->configureWriteCallback(this);
}

BluetoothServer::~BluetoothServer()
{
    delete bt;
}

bool BluetoothServer::isCommand(String request, String command)
{
    if (command.length() >= request.length())
    {
        return false;
    }
    return command.equals(request.substring(0, command.length()));
}

String BluetoothServer::getData(String request, String command)
{
    if (command.length() >= request.length())
    {
        return "";
    }
    return request.substring(command.length());
}

void BluetoothServer::onRequest(String request)
{
    if (request.length() > 0)
    {
        //Definimos los comandos validos
        const String DELETE_WIFI = "$DELETE_WIFI$";
        const String TURN_LED_ON = "$TURN_LED_ON$";
        const String TURN_LED_OFF = "$TURN_LED_OFF$";
        //------------------------------

        if (isCommand(request, TURN_LED_ON))
        {
            digitalWrite(LED_BUILTIN, HIGH);
            sendResponse(OK);
            return;
        }
        if (isCommand(request, TURN_LED_OFF))
        {
            digitalWrite(LED_BUILTIN, LOW);
            sendResponse(OK);
            return;
        }
        if (isCommand(request, DELETE_WIFI))
        {
            Serial.println(getData(request, DELETE_WIFI));
            sendResponse(OK);
            return;
        }
        Serial.println("Unrecognized Bluetooth request: " + request);
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

void BluetoothServer::sendResponse(String response)
{
    bt->transmitData(response);
}