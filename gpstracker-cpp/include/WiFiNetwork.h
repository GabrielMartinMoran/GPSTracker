#ifndef WiFiNetwork_h
#define WiFiNetwork_h

#include <iostream>
#include <interfaces/IWiFiNetwork.h>

class WiFiNetwork : public IWiFiNetwork
{
  private:
    std::string SSID;
    std::string password;
  public:
    WiFiNetwork(std::string SSID, std::string password);
    std::string toString();
    std::string toCSVLine();
    std::string getSSID();
    std::string getPassword();
};

#endif