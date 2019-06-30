#include "platformioDependent/Bluetooth.h"

Bluetooth::~Bluetooth()
{
}

void Bluetooth::start(IBluetoothServer *btServer)
{
    // Create the BLE Device
    BLEDevice::init(DEVICE_BT_NAME);

    // Create the BLE Server
    pServer = BLEDevice::createServer();
    serverCallbacks = new BluetoothServerCallbacks(this);
    pServer->setCallbacks(serverCallbacks);

    // Create the BLE Service
    pService = pServer->createService(SERVICE_UUID);

    // Create a BLE Characteristic
    txCharacteristic = pService->createCharacteristic(
        CHARACTERISTIC_UUID_TX,
        BLECharacteristic::PROPERTY_NOTIFY);

    descriptor = new BLE2902();
    txCharacteristic->addDescriptor(descriptor);

    rxCharacteristic = pService->createCharacteristic(
        CHARACTERISTIC_UUID_RX,
        BLECharacteristic::PROPERTY_WRITE);

    writeCallback = new BluetoothWriteCallback();
    rxCharacteristic->setCallbacks(writeCallback);

    // Start the service
    pService->start();

    // Start advertising
    adverising = pServer->getAdvertising();
    adverising->start();

    writeCallback->configureServer(btServer);

    Serial.println("BLE Turned On!");
}

void Bluetooth::stop()
{    
    BLEDevice::deinit();
    delete pServer;
    delete serverCallbacks;
    delete pService;
    delete txCharacteristic;
    delete descriptor;
    delete rxCharacteristic;
    delete writeCallback;
    delete adverising;    

    Serial.println("BLE Turned Off!");
}

void Bluetooth::transmitData(std::string data)
{
    if (!deviceConnected)
    {
        return;
    }
    txCharacteristic->setValue(data);
    txCharacteristic->notify();
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