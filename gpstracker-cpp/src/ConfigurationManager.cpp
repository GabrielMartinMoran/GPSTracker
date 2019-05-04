#include <ConfigurationManager.h>

void ConfigurationManager::init(){
    WiFiConfiguration wifiConfiguration = WiFiConfiguration();
}

WiFiConfiguration ConfigurationManager::getWiFiConfiguration(){
    return wifiConfiguration;
}