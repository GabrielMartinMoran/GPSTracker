#ifndef BluetoothServer_h
#define BluetoothServer_h

#include <iostream>
#include <interfaces/IBluetoothServer.h>
#include <interfaces/IBluetooth.h>
#include <interfaces/IWiFiConfiguration.h>
#include <interfaces/ISerialController.h>
#include <utils/StringTokenizer.h>
#include <EndConfigurationCallback.h>

#define OK "200"
#define ERROR "400"

// SERVER COMMANDS
#define DELETE_NETWORK "$DELETE_NETWORK$"
#define TURN_LED_ON "A" //"$TURN_LED_ON$";
#define TURN_LED_OFF "B" //"$TURN_LED_OFF$";
#define LIST_NETWORKS "$LIST_NETWORKS$"
#define ADD_NETWORK "$ADD_NETWORK$"
#define END_CONFIGURATION "$END_CONFIGURATION$"
#define ECHO "$ECHO$"

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
    EndConfigurationCallback *endConfigurationCallback;
    bool isCommand(std::string request, std::string command);
    std::string getData(std::string request, std::string command);

public:
    BluetoothServer(IWiFiConfiguration *wifiConfiguration, IBluetooth *bluetooth, ISerialController *serialController);
    ~BluetoothServer();
    void start();
    void stop();
    void onRequest(std::string request);
    void sendResponse(std::string response);
    void setEndConfigurationCallback(EndConfigurationCallback *endConfigurationCallback);
};

#endif