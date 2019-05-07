#ifndef WiFiConfigurationMockup_h
#define WiFiConfigurationMockup_h

#include <iostream>
#include <interfaces/IWiFiConfiguration.h>
#include <interfaces/IWiFiNetwork.h>

class WiFiConfigurationMockup : public IWiFiConfiguration
{
public:
    void loadConfiguration() {};
    size_t getConfiguredNetworks() {return 0;}
    IWiFiNetwork *getNetworkAtPosition(unsigned int index) {return nullptr;}
    void removeNetwork(unsigned int index) {}
    void addNetwork(std::string SSID, std::string password) {}
    bool addNetworkFromCSVLine(std::string SSIDNetworkCSV) {return true;}
    void deleteConfigurationFile() {}
    std::string listNetworks() {return "";}
    bool deleteNetwork(std::string SSID) {return true;}
};

#endif