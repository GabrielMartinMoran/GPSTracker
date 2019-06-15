#ifndef BluetoothMockup_h
#define BluetoothMockup_h

#include <interfaces/IBluetooth.h>
#include <interfaces/IBluetoothServer.h>
#include <iostream>

class BluetoothMockup : public IBluetooth
{
public:
    std::string transmittedData;
    BluetoothMockup(){};
    ~BluetoothMockup(){};
    void start(IBluetoothServer *btServer) {}
    void stop() {}
    void setConnectionStatus(bool value) {}
    bool isConnected() { return true; }
    void configureWriteCallback(IBluetoothServer *btServer) {}
    void transmitData(std::string data) { transmittedData = data; }
};

#endif