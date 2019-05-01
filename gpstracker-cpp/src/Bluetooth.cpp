#include "Bluetooth.h"

Bluetooth::Bluetooth()
{
    pinMode(LED_PIN, OUTPUT);

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
    Serial.println("BLE Turned On!");
}

Bluetooth::~Bluetooth()
{
    delete writeCallback;
    delete pCharacteristic;
    
}

void Bluetooth::transmitData(String data){
    if(!deviceConnected){
        return;
    }
    char buffer[data.length() + 1];
    data.toCharArray(buffer, data.length() + 1);
    pCharacteristic->setValue(buffer);
    pCharacteristic->notify(); // Send the value
}

void Bluetooth::startConnectionLoop()
{
    if (deviceConnected)
    {
        // Fabricate some arbitrary junk for now...
        txValue = 1.5f;

        // Let's convert the value to a char array:
        char txString[8];                 // make sure this is big enuffz
        dtostrf(txValue, 1, 2, txString); // float_val, min_width, digits_after_decimal, char_buffer

        //    pCharacteristic->setValue(&txValue, 1); // To send the integer value
        //    pCharacteristic->setValue("Hello!"); // Sending a test message
        pCharacteristic->setValue(txString);

        pCharacteristic->notify(); // Send the value to the app!
        Serial.print("*** Sent Value: ");
        Serial.print(txString);
        Serial.println(" ***");

        // You can add the rxValue checks down here instead
        // if you set "rxValue" as a global var at the top!
        // Note you will have to delete "std::string" declaration
        // of "rxValue" in the callback function.
        //    if (rxValue.find("A") != -1) {
        //      Serial.println("Turning ON!");
        //      digitalWrite(LED, HIGH);
        //    }
        //    else if (rxValue.find("B") != -1) {
        //      Serial.println("Turning OFF!");
        //      digitalWrite(LED, LOW);
        //    }
    }
    delay(1000);
}

void Bluetooth::setConnectionStatus(bool value)
{
    deviceConnected = value;
}

bool Bluetooth::isConnected()
{
    return deviceConnected;
}

void Bluetooth::configureWriteCallback(BluetoothServer *btServer)
{
    writeCallback->configureServer(btServer);
}