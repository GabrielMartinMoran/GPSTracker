#ifndef Orchestator_h
#define Orchestator_h

#include <pthread.h>
#include <iostream>
#include <interfaces/ISDManager.h>
#include <platformDependent/SDManager.h>
#include <platformDependent/SerialController.h>
#include <BluetoothServer.h>
#include <WiFiConfiguration.h>
#include <platformDependent/Bluetooth.h>
#include <platformDependent/WiFiConnector.h>
#include <EndConfigurationCallback.h>
#include <GPS/GPS.h>
#include <platformDependent/GPSController.h>
#include <platformDependent/IOManager.h>
#include <platformDependent/HTTPClient.h>
#include <platformDependent/LedBlinker.h>

#define DEVICE_NAME "SRG-SVMI"
#define HTTP_CODE_OK 200
#define BLUETOOTH_SERVER_THREAD_STACK_SIZE (3 * 1024)
#define WIFI_CONNECTOR_THREAD_STACK_SIZE (2 * 1024)
#define SD_CARD_PIN 5
#define GPS_UART_NUMBER 2
#define METERS_BETWEEN_POINTS 20

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
    GPSController *gpsController;
    IOManager *ioManager;
    EndConfigurationCallback *endConfigurationCallback;
    static void *startWiFiConnector(void *wifiConnector);
    static void *startBluetoothServer(void *btServer);
    void sendAvailableData();
    void startBluetoothConfiguration();
public:
    Orchestator();
    ~Orchestator();
    void start();
};

#endif