#ifndef IWiFiConfiguration_h
#define IWiFiConfiguration_h

#include <iostream>
#include <interfaces/ISDManager.h>
#include <interfaces/IWiFiNetwork.h>

class IWiFiConfiguration
{
public:
  virtual ~IWiFiConfiguration() {}
  virtual void loadConfiguration() = 0;
  virtual size_t getConfiguredNetworks() = 0;
  virtual IWiFiNetwork *getNetworkAtPosition(unsigned int index) = 0;
  virtual void removeNetwork(unsigned int index) = 0;
  virtual void addNetwork(std::string SSID, std::string password) = 0;
  virtual bool addNetworkFromCSVLine(std::string SSIDNetworkCSV) = 0;
  virtual void deleteConfigurationFile() = 0;
  virtual std::string listNetworks() = 0;
  virtual bool deleteNetwork(std::string SSID) = 0;
  virtual IWiFiNetwork *getNetwork(std::string SSID) = 0;
};

#endif