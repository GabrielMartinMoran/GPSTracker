#include <BLEDevice.h>
#include <BLEServer.h>
//#include <BLEUtils.h>
#include <BLE2902.h>
#include <Arduino.h>

#define SERVICE_UUID "6E400001-B5A3-F393-E0A9-E50E24DCCA9E"
#define CHARACTERISTIC_UUID_RX "6E400002-B5A3-F393-E0A9-E50E24DCCA9E"
#define CHARACTERISTIC_UUID_TX "6E400003-B5A3-F393-E0A9-E50E24DCCA9E"

#define LED_PIN 2
#define DEVICE_BT_NAME "ESP32 GPS Tracker"

class Bluetooth
{
  private:
    BLECharacteristic *pCharacteristic;
    bool deviceConnected = false;
    float txValue = 0;

  public:
    Bluetooth();
    void startConnectionLoop();
    void setConnectionStatus(bool value);
    bool isConnected();
};

class BTServerCallbacks : public BLEServerCallbacks
{
  private:
    Bluetooth *bluetooth;
    void onConnect(BLEServer *pServer);
    void onDisconnect(BLEServer *pServer);

  public:
    BTServerCallbacks(Bluetooth *bluetooth);
    ~BTServerCallbacks();
};

class BTWriteCallback : public BLECharacteristicCallbacks
{
  private:
    void onWrite(BLECharacteristic *pCharacteristic);
};