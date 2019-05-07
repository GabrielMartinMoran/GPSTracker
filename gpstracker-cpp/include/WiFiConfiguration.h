#ifndef WiFiConfiguration_h
#define WiFiConfiguration_h

#include <iostream>
#include <Configuration.h>
#include <interfaces/ISDManager.h>
#include <StringTokenizer.h>
#include <WiFiNetwork.h>

#define DATA_SEPARATOR ","
#define WIFI_CONFIGURATION_FILENAME "/WiFiConfig"

class WiFiConfiguration : public Configuration
{
private:
  ISDManager *sdManager;
  std::vector<WiFiNetwork *> *networks;
  void saveConfiguration();
  bool addNetworkToMemory(std::string SSIDNetworkCSV);

public:
  WiFiConfiguration(ISDManager *sdManager);
  ~WiFiConfiguration();
  void loadConfiguration();
  unsigned int getConfiguredNetworks();
  WiFiNetwork *getNetworkAtPosition(unsigned int index);
  void removeNetwork(unsigned int index);
  void addNetwork(std::string SSID, std::string password);
  bool addNetworkFromCSVLine(std::string SSIDNetworkCSV);
  void deleteConfigurationFile();
  std::string listNetworks();
  bool deleteNetwork(std::string SSID);
};

#endif