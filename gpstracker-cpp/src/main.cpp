#include <Arduino.h>
#include <BluetoothServer.h>

void setup()
{
    Serial.begin(115200);

    BluetoothServer *btServer = new BluetoothServer();

    //delete bt;
    Serial.println("~~ Fin del setup ~~");
}

void loop()
{
}