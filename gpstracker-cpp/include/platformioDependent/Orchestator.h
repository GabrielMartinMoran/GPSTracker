#ifndef Orchestator_h
#define Orchestator_h

#include <thread>
#include <iostream>
#include <platformioDependent/SDManager.h>
#include <platformioDependent/SerialController.h>
#include <BluetoothServer.h>
#include <WiFiConfiguration.h>
#include <platformioDependent/Bluetooth.h>
#include <platformioDependent/WiFiConnector.h>
#include <EndConfigurationCallback.h>
#include <GPS/GPS.h>
#include <platformioDependent/GPSController.h>
#include <platformioDependent/IOManager.h>

class Orchestator
{
private:
    SerialController *serialController;
    SDManager *sdManager;
    WiFiConfiguration *wifiConfiguration;
    Bluetooth *bluetooth;
    BluetoothServer *btServer;
    WiFiConnector *wifiConnector;
    GPS *gps;
    EndConfigurationCallback *endConfigurationCallback;
    static void startWiFiConnector();
    static void startBluetoothServer(BluetoothServer *btServer);
    static void startNetworkDataSender();
    static void startGPSDataProvider(IOManager *ioManager, GPS *gps);

public:
    Orchestator();
    ~Orchestator();
    void start();
};

#endif