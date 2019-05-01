#ifndef WiFiConfiguration_h
#define WiFiConfiguration_h

#include <iostream>
#include <Configuration.h>
#include <SDManager.h>
#include "Utils/StringTokenizer.h"
#include <WiFiNetwork.h>

#define DATA_SEPARATOR ","
#define WIFI_CONFIGURATION_FILENAME "/WiFiConfig"

class WiFiConfiguration : public Configuration
{
private:
  SDManager *sdManager;
  std::vector<WiFiNetwork *> *networks;
  void saveConfiguration();

public:
  WiFiConfiguration();
  ~WiFiConfiguration();
  void loadConfiguration();
  void printConfiguratedNetworks();
  unsigned int getConfiguredNetworks();
  WiFiNetwork *getNetworkAtPosition(unsigned int index);
  void removeNetwork(unsigned int index);
  void addNetwork(String SSID, String password);
  void deleteConfigurationFile();
};

#endif