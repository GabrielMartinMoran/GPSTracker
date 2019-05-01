#ifndef WiFiNetwork_h
#define WiFiNetwork_h

#include <Arduino.h>

class WiFiNetwork
{
  public:
    String SSID;
    String password;
    WiFiNetwork(String SSID, String password);
    String toString();
    String toCSVLine();
};

#endif