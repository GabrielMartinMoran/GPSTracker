#ifndef IBluetooth_h
#define IBluetooth_h

#include <iostream>
#include <interfaces/IBluetoothServer.h>

//Forward declaration
class IBluetoothServer;

class IBluetooth
{
  public:
    virtual void startConnectionLoop() {}
    virtual void setConnectionStatus(bool value) {}
    virtual bool isConnected() {return 0;}
    virtual void configureWriteCallback(IBluetoothServer *btServer) {}
    virtual void transmitData(std::string data) {}
};

#endif