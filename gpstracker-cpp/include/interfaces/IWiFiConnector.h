#ifndef IWiFiConnector_h
#define IWiFiConnector_h

#include <iostream>
#include <vector>

class IWiFiConnector
{
public:
    ~IWiFiConnector() {}
    virtual bool connect(std::string SSID, std::string password) = 0;
    virtual void disconnect() = 0;
    virtual std::vector<std::string> getAvaliableNetworks() = 0;
    virtual bool isNetworkAvaliable(std::string SSID) = 0;
    virtual bool isConnected() = 0;
};

#endif