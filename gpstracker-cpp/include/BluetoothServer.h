#ifndef BluetoothServer_h
#define BluetoothServer_h

#include <iostream>
//#include <Arduino.h>
#include <interfaces/IBluetoothServer.h>
#include <interfaces/IBluetooth.h>
#include <interfaces/IWiFiConfiguration.h>
#include <StringTokenizer.h>

#define OK "200"
#define ERROR "400"

//Forward declaration
class IBluetooth;
class IWiFiConfiguration;

class BluetoothServer : public IBluetoothServer
{
private:
    IBluetooth *bt;
    IWiFiConfiguration *wifiConfiguration;
    bool isCommand(std::string request, std::string command);
    std::string getData(std::string request, std::string command);

public:
    BluetoothServer(IWiFiConfiguration *wifiConfiguration, IBluetooth *bluetooth);
    ~BluetoothServer();
    void onRequest(std::string request);
    void sendResponse(std::string response);
};

#endif