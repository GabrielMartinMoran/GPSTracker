#ifndef BluetoothServer_h
#define BluetoothServer_h

#include <iostream>
//#include <Arduino.h>
#include <interfaces/IBluetoothServer.h>
#include <interfaces/IBluetooth.h>
#include <interfaces/IWiFiConfiguration.h>
#include <interfaces/ISerialController.h>
#include <StringTokenizer.h>

#define OK "200"
#define ERROR "400"

// SERVER COMMANDS
#define DELETE_NETWORK "$DELETE_NETWORK$"
#define TURN_LED_ON "A" //"$TURN_LED_ON$";
#define TURN_LED_OFF "B" //"$TURN_LED_OFF$";
#define LIST_NETWORKS "$LIST_NETWORKS$"
#define ADD_NETWORK "$ADD_NETWORK$"

//Forward declaration
class IBluetooth;
class IWiFiConfiguration;
//class ISerialController;

class BluetoothServer : public IBluetoothServer
{
private:
    IBluetooth *bluetooth;
    IWiFiConfiguration *wifiConfiguration;
    ISerialController *serialController;
    bool isCommand(std::string request, std::string command);
    std::string getData(std::string request, std::string command);

public:
    BluetoothServer(IWiFiConfiguration *wifiConfiguration, IBluetooth *bluetooth, ISerialController *serialController);
    ~BluetoothServer();
    void start();
    void stop();
    void onRequest(std::string request);
    void sendResponse(std::string response);
};

#endif