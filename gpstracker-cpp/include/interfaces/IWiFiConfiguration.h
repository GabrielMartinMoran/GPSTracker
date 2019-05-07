#ifndef IWiFiConfiguration_h
#define IWiFiConfiguration_h

#include <iostream>
#include <interfaces/ISDManager.h>
#include <interfaces/IWiFiNetwork.h>

class IWiFiConfiguration
{
public:
  virtual ~IWiFiConfiguration() {}
  virtual void loadConfiguration() {}
  virtual size_t getConfiguredNetworks() {return 0;}
  virtual IWiFiNetwork *getNetworkAtPosition(unsigned int index) {return nullptr;}
  virtual void removeNetwork(unsigned int index) {}
  virtual void addNetwork(std::string SSID, std::string password) {}
  virtual bool addNetworkFromCSVLine(std::string SSIDNetworkCSV) {return 0;}
  virtual void deleteConfigurationFile() {}
  virtual std::string listNetworks() {return "";}
  virtual bool deleteNetwork(std::string SSID) {return 0;}
};

#endif