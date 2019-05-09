#ifndef WiFiConfigurationMockup_h
#define WiFiConfigurationMockup_h

#include <iostream>
#include <interfaces/IWiFiConfiguration.h>
#include <interfaces/IWiFiNetwork.h>

class WiFiConfigurationMockup : public IWiFiConfiguration
{
public:
    std::string deletedNetowkSSID;
    std::string networksStrList;
    std::string networkFromCSVLine;
    void loadConfiguration() {}
    size_t getConfiguredNetworks() {return 0;}
    IWiFiNetwork *getNetworkAtPosition(unsigned int index) {return nullptr;}
    void removeNetwork(unsigned int index) {}
    void addNetwork(std::string SSID, std::string password) {}
    bool addNetworkFromCSVLine(std::string SSIDNetworkCSV) {
        networkFromCSVLine = SSIDNetworkCSV;
    }
    void deleteConfigurationFile() {}
    std::string listNetworks() {
        return networksStrList;
    }
    bool deleteNetwork(std::string SSID) {
        deletedNetowkSSID = SSID;
        return true;
    }
    IWiFiNetwork *getNetwork(std::string SSID){
        return nullptr;
    }
};

#endif