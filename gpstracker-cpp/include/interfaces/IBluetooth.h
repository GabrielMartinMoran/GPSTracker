#ifndef IBluetooth_h
#define IBluetooth_h

#include <iostream>
#include <interfaces/IBluetoothServer.h>

//Forward declaration
class IBluetoothServer;

class IBluetooth
{
  public:
    virtual ~IBluetooth() {}
    virtual void start(IBluetoothServer *btServer) = 0;
    virtual void stop() = 0;
    virtual void setConnectionStatus(bool value) = 0;
    virtual bool isConnected() = 0;
    virtual void configureWriteCallback(IBluetoothServer *btServer) = 0;
    virtual void transmitData(std::string data) = 0;
};

#endif