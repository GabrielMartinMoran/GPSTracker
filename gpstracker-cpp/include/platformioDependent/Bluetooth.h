#ifndef Bluetooth_h
#define Bluetooth_h


#include <interfaces/IBluetooth.h>
#include <iostream>
#include <BLEDevice.h>
//#include <BLEServer.h>
#include <BLECharacteristic.h>
//#include <BLEUtils.h>
#include <BLE2902.h>
#include <Arduino.h>
#include <platformioDependent/BluetoothWriteCallback.h>
#include <platformioDependent/BluetoothServerCallbacks.h>

#define SERVICE_UUID "6E40F1B0-B5A3-F393-E0A9-E50E24DCCA9E"
#define CHARACTERISTIC_UUID_RX "6E40F1B1-B5A3-F393-E0A9-E50E24DCCA9E"
#define CHARACTERISTIC_UUID_TX "6E40F1B2-B5A3-F393-E0A9-E50E24DCCA9E"

#define LED_PIN 2
#define DEVICE_BT_NAME "ESP32 GPS Tracker"

//Forward declaration
class BluetoothServer;
class BluetoothWriteCallback;
class BluetoothServerCallbacks;

class Bluetooth : public IBluetooth
{
  private:    
    BLECharacteristic *pCharacteristic;
    BluetoothWriteCallback *writeCallback;
    bool firstInit = true;
    bool deviceConnected = false;
    float txValue = 0;

  public:
    ~Bluetooth();
    void start(IBluetoothServer *btServer);
    void stop();
    void setConnectionStatus(bool value);
    bool isConnected();
    void configureWriteCallback(IBluetoothServer *btServer);
    void transmitData(std::string data);
};

#endif