#include <platformioDependent/BluetoothWriteCallback.h>

void BluetoothWriteCallback::configureServer(IBluetoothServer *btServer)
{
    this->btServer = btServer;
}

void BluetoothWriteCallback::onWrite(BLECharacteristic *pCharacteristic)
{
    std::string rxValue = pCharacteristic->getValue().c_str();

    btServer->onRequest(rxValue);
}