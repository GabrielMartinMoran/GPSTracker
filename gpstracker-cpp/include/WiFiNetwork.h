#ifndef WiFiNetwork_h
#define WiFiNetwork_h

#include <iostream>

class WiFiNetwork
{
  public:
    std::string SSID;
    std::string password;
    WiFiNetwork(std::string SSID, std::string password);
    std::string toString();
    std::string toCSVLine();
};

#endif