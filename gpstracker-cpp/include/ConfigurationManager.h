#ifndef ConfigurationManager_h
#define ConfigurationManager_h

#include <WiFiConfiguration.h>

class ConfigurationManager
{
  private:
    static WiFiConfiguration wifiConfiguration;
  public:
    static void init();
    static WiFiConfiguration getWiFiConfiguration();
};

#endif