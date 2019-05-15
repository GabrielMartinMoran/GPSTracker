#ifndef WiFiConfiguration_h
#define WiFiConfiguration_h

#include <iostream>
#include <interfaces/ISDManager.h>
#include <interfaces/IWiFiConfiguration.h>
#include <utils/StringTokenizer.h>
#include <WiFiNetwork.h>

#define DATA_SEPARATOR ","
#define WIFI_CONFIGURATION_FILENAME "/WiFiConfig"

class WiFiConfiguration : public IWiFiConfiguration
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
  size_t getConfiguredNetworks();
  WiFiNetwork *getNetworkAtPosition(unsigned int index);
  void removeNetwork(unsigned int index);
  void addNetwork(std::string SSID, std::string password);
  bool addNetworkFromCSVLine(std::string SSIDNetworkCSV);
  void deleteConfigurationFile();
  std::string listNetworks();
  bool deleteNetwork(std::string SSID);
  WiFiNetwork *getNetwork(std::string SSID);
};

#endif