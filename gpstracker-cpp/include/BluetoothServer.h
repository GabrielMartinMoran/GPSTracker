#ifndef BluetoothServer_h
#define BluetoothServer_h

#include <Arduino.h>
#include <Bluetooth.h>

class Bluetooth;

class BluetoothServer
{
  private:
    Bluetooth *bt;

  public:
    BluetoothServer();
    ~BluetoothServer();
    void onRequest(String request);
    void sendResponse(String response);
};

#endif