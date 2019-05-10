#ifndef Orchestator_h
#define Orchestator_h

#include <thread>
#include <iostream>
#include <SDManager.h>
#include <SerialController.h>
#include <BluetoothServer.h>
#include <WiFiConfiguration.h>
#include <Bluetooth.h>
#include <WiFiConnector.h>

class Orchestator
{
private:
    SerialController *serialController;
    SDManager *sdManager;
    WiFiConfiguration *wifiConfiguration;
    Bluetooth *bluetooth;
    BluetoothServer *btServer;
    WiFiConnector *wifiConnector;
    static void startWiFiConnector();
    static void startBluetoothServer();
    static void startNetworkDataSender();
    static void startGPSDataProvider();

public:
    Orchestator();
    ~Orchestator();
    void start();
};

#endif