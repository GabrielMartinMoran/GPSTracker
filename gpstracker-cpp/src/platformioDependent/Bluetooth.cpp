#include "platformioDependent/Bluetooth.h"

Bluetooth::~Bluetooth()
{
    stop();
}

void Bluetooth::start(IBluetoothServer *btServer)
{
    

    if (firstInit)
    {
        Serial.println("FIRST INIT");
        // Create the BLE Device
        BLEDevice::init(DEVICE_BT_NAME);

        writeCallback = new BluetoothWriteCallback();

        serverCallback = new BluetoothServerCallbacks(this);

        // Create the BLE Server
        pServer = BLEDevice::createServer();
        pServer->setCallbacks(serverCallback);

        // Create the BLE Service
        pService = pServer->createService(SERVICE_UUID);

        // Create a BLE Characteristic
        notifyCharacteristic = pService->createCharacteristic(
            CHARACTERISTIC_UUID_TX,
            BLECharacteristic::PROPERTY_NOTIFY);

        descriptor = new BLE2902();
        notifyCharacteristic->addDescriptor(descriptor);

        writeCharacteristic = pService->createCharacteristic(
            CHARACTERISTIC_UUID_RX,
            BLECharacteristic::PROPERTY_WRITE);

        writeCharacteristic->setCallbacks(writeCallback);

        writeCallback->configureServer(btServer);


        // Start the service
        pService->start();
        
        firstInit = false;
    }    

    // Start advertising
    pServer->getAdvertising()->start();
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

    // Start advertising
    pServer->getAdvertising()->stop();
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
    writeCharacteristic->setValue(data);
    writeCharacteristic->notify(); // Send the value
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