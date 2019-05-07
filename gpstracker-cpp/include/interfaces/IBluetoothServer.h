#ifndef IBluetoothServer_h
#define IBluetoothServer_h

#include <iostream>

class IBluetoothServer
{
public:
    virtual void onRequest(std::string request) {}
    virtual void sendResponse(std::string response) {}
};

#endif