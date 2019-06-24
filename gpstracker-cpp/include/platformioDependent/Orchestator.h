#ifndef Orchestator_h
#define Orchestator_h

#include <thread>
#include <iostream>
#include <interfaces/ISDManager.h>
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
#include <platformioDependent/HTTPClient.h>

#include <Arduino.h>

#define DEVICE_NAME "SRG-SVMI"
#define HTTP_CODE_OK 200


class Orchestator
{
private:
    SerialController *serialController;
    ISDManager *sdManager;
    WiFiConfiguration *wifiConfiguration;
    Bluetooth *bluetooth;
    BluetoothServer *btServer;
    WiFiConnector *wifiConnector;
    GPS *gps;
    IOManager *ioManager;
    EndConfigurationCallback *endConfigurationCallback;
    static void startWiFiConnector(WiFiConnector *wifiConnector);
    static void startBluetoothServer(BluetoothServer *btServer);
    static void startNetworkDataSender();
    static void startGPSDataProvider(IOManager *ioManager, GPS *gps, SerialController *serialController);

public:
    Orchestator();
    ~Orchestator();
    void start();
};

#endif