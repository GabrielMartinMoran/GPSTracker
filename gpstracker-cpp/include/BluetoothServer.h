#ifndef BluetoothServer_h
#define BluetoothServer_h

#include <Arduino.h>
#include <Bluetooth.h>
#include <WiFiConfiguration.h>

#define OK "200"
#define ERROR "400"

class Bluetooth;
class ConfigurationManager;

class BluetoothServer
{
private:
  Bluetooth *bt;
  WiFiConfiguration *wifiConfiguration;
  bool isCommand(String request, String command);
  String getData(String request, String command);

public:
  BluetoothServer(WiFiConfiguration *wifiConfiguration);
  ~BluetoothServer();
  void onRequest(String request);
  void sendResponse(String response);
};

#endif