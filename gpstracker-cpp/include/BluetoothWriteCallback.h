#ifndef BluetoothWriteCallback_h
#define BluetoothWriteCallback_h

#include <BLECharacteristic.h>
#include <Arduino.h>
#include <BluetoothServer.h>

class BluetoothServer;

class BluetoothWriteCallback : public BLECharacteristicCallbacks
{
  private:
    BluetoothServer *btServer;
    void onWrite(BLECharacteristic *pCharacteristic);

  public:
    void configureServer(BluetoothServer *btServer);
};

#endif