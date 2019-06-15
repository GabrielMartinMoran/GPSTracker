#ifndef BluetoothServerCallbacks_h
#define BluetoothServerCallbacks_h

#include <BLEServer.h>
#include <platformioDependent/Bluetooth.h>

class Bluetooth;

class BluetoothServerCallbacks : public BLEServerCallbacks
{
private:
    Bluetooth *bluetooth;
    void onConnect(BLEServer *pServer);
    void onDisconnect(BLEServer *pServer);

public:
    BluetoothServerCallbacks(Bluetooth *bluetooth);
    ~BluetoothServerCallbacks();
};

#endif