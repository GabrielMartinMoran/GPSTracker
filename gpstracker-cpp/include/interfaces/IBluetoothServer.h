#ifndef IBluetoothServer_h
#define IBluetoothServer_h

#include <iostream>

class IBluetoothServer
{
public:
    virtual ~IBluetoothServer() {}
    virtual void start() {}
    virtual void stop() {}
    virtual void onRequest(std::string request) {}
    virtual void sendResponse(std::string response) {}
};

#endif