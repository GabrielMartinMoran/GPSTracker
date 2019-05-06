#ifndef BluetoothServer_h
#define BluetoothServer_h

#include <iostream>
#include <Arduino.h>
#include <Bluetooth.h>
#include <WiFiConfiguration.h>
#include <StringTokenizer.h>

#define OK "200"
#define ERROR "400"

class Bluetooth;
class ConfigurationManager;

class BluetoothServer
{
private:
    Bluetooth *bt;
    WiFiConfiguration *wifiConfiguration;
    bool isCommand(std::string request, std::string command);
    std::string getData(std::string request, std::string command);

public:
    BluetoothServer(WiFiConfiguration *wifiConfiguration);
    ~BluetoothServer();
    void onRequest(std::string request);
    void sendResponse(std::string response);
};

#endif