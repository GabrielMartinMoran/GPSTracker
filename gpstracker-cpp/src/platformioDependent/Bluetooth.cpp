#include "platformioDependent/Bluetooth.h"

Bluetooth::~Bluetooth()
{
    stop();
}

void Bluetooth::start(IBluetoothServer *btServer)
{
    // Create the BLE Device
    BLEDevice::init(DEVICE_BT_NAME);

    // Create the BLE Server
    BLEServer *pServer = BLEDevice::createServer();
    pServer->setCallbacks(new BluetoothServerCallbacks(this));

    // Create the BLE Service
    BLEService *pService = pServer->createService(SERVICE_UUID);

    // Create a BLE Characteristic
    pCharacteristic = pService->createCharacteristic(
        CHARACTERISTIC_UUID_TX,
        BLECharacteristic::PROPERTY_NOTIFY);

    pCharacteristic->addDescriptor(new BLE2902());

    BLECharacteristic *pCharacteristic = pService->createCharacteristic(
        CHARACTERISTIC_UUID_RX,
        BLECharacteristic::PROPERTY_WRITE);

    writeCallback = new BluetoothWriteCallback();
    pCharacteristic->setCallbacks(writeCallback);

    // Start the service
    pService->start();

    // Start advertising
    pServer->getAdvertising()->start();

    writeCallback->configureServer(btServer);

    Serial.println("BLE Turned On!");

}

void Bluetooth::stop()
{
    /*
    // Start the service
    pService->stop();

    // Start advertising
    pServer->getAdvertising()->stop();
    */

    // Start the service
    //pService->stop();

    //pServer->getAdvertising()->stop();
    BLEDevice::deinit();
    /*
    delete pServer;
    delete pService;
    delete descriptor;
    delete writeCallback;
    delete serverCallback;
    delete notifyCharacteristic;
    delete writeCharacteristic;*/

    Serial.println("BLE Turned Off!");
}

void Bluetooth::transmitData(std::string data)
{
    if (!deviceConnected)
    {
        return;
    }
    //char buffer[data.length() + 1];
    //data.toCharArray(buffer, data.length() + 1);
    pCharacteristic->setValue(data);
    pCharacteristic->notify(); // Send the value

}

void Bluetooth::setConnectionStatus(bool value)
{
    deviceConnected = value;
}

bool Bluetooth::isConnected()
{
    return deviceConnected;
}

void Bluetooth::configureWriteCallback(IBluetoothServer *btServer)
{
    writeCallback->configureServer(btServer);
}