#ifndef BluetoothServer_h
#define BluetoothServer_h

#include <Arduino.h>
#include <Bluetooth.h>

#define OK "200"
#define ERROR "400"

class Bluetooth;

class BluetoothServer
{
private:
  Bluetooth *bt;
  bool isCommand(String request, String command);
  String getData(String request, String command);

public:
  BluetoothServer();
  ~BluetoothServer();
  void onRequest(String request);
  void sendResponse(String response);
};

#endif