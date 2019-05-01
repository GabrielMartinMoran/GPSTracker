#include <BluetoothServerCallbacks.h>

BluetoothServerCallbacks::BluetoothServerCallbacks(Bluetooth *bt)
{
    bluetooth = bt;
}

BluetoothServerCallbacks::~BluetoothServerCallbacks()
{
    delete bluetooth;
}

void BluetoothServerCallbacks::onConnect(BLEServer *pServer)
{
    bluetooth->setConnectionStatus(true);
};

void BluetoothServerCallbacks::onDisconnect(BLEServer *pServer)
{
    bluetooth->setConnectionStatus(false);
}