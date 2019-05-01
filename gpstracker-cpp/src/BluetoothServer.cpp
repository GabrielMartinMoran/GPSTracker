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

void BluetoothServer::onRequest(String request)
{
    if (request.length() > 0)
    {
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
        else
        {
            Serial.print("Command not recognized!");
        }

        Serial.println();
        Serial.println("*********");
    }
}

void BluetoothServer::sendResponse(String response)
{
    bt->transmitData(response);
}