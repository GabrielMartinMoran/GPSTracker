#ifndef WiFiNetwork_h
#define WiFiNetwork_h

#include <iostream>
#include <interfaces/IWiFiNetwork.h>

class WiFiNetwork : public IWiFiNetwork
{
  public:
    std::string SSID;
    std::string password;
    WiFiNetwork(std::string SSID, std::string password);
    std::string toString();
    std::string toCSVLine();
};

#endif