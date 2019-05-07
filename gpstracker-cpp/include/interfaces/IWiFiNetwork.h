#ifndef IWiFiNetwork_h
#define IWiFiNetwork_h

#include <iostream>

class IWiFiNetwork
{
  public:
    std::string SSID;
    std::string password;
    virtual ~IWiFiNetwork(){}
    virtual std::string toString() {return "";}
    virtual std::string toCSVLine() {return "";}
};

#endif