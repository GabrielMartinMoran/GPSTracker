#ifndef BluetoothWriteCallback_h
#define BluetoothWriteCallback_h

#include <BLECharacteristic.h>
#include <interfaces/IBluetoothServer.h>
#include <Arduino.h>
#include <iostream>

class IBluetoothServer;

class BluetoothWriteCallback : public BLECharacteristicCallbacks
{
private:
    IBluetoothServer *btServer;
    void onWrite(BLECharacteristic *pCharacteristic);

public:
    void configureServer(IBluetoothServer *btServer);
};

#endif