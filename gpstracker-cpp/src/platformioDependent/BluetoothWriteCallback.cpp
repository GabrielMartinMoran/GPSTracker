#include <platformioDependent/BluetoothWriteCallback.h>

void BluetoothWriteCallback::configureServer(IBluetoothServer *btServer)
{
    this->btServer = btServer;
}

void BluetoothWriteCallback::onWrite(BLECharacteristic *pCharacteristic)
{
    std::string rxValue = pCharacteristic->getValue().c_str();

    btServer->onRequest(rxValue);
    /*
    if (rxValue.length() > 0)
    {
        Serial.println("*********");
        Serial.print("Received Value: ");

        for (int i = 0; i < rxValue.length(); i++)
        {
            Serial.print(rxValue[i]);
        }

        Serial.println();

        // Do stuff based on the command received from the app
        if (rxValue == "A")
        {
            Serial.print("Turning ON!");
            digitalWrite(LED_BUILTIN, HIGH);
        }
        else if (rxValue == "B")
        {
            Serial.print("Turning OFF!");
            digitalWrite(LED_BUILTIN, LOW);
        }
        else
        {
            Serial.print("Command not recognized!");
        }

        Serial.println();
        Serial.println("*********");
    }
    */
    
}