#ifndef IWiFiNetwork_h
#define IWiFiNetwork_h

#include <iostream>

class IWiFiNetwork
{
public:
    virtual ~IWiFiNetwork() {}
    virtual std::string toString() = 0;
    virtual std::string toCSVLine() = 0;
    virtual std::string getSSID() = 0;
    virtual std::string getPassword() = 0;
};

#endif