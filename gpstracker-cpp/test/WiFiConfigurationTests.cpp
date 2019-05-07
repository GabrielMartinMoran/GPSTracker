#include <gtest/gtest.h>
#include <SDManagerMockup.h>
#include <WiFiConfiguration.h>
#include <iostream>

TEST(WiFiConfiguration, getConfiguredNetworks)
{
    SDManagerMockup *sdManager = new SDManagerMockup();
    
    //Llenamos un vector con lineas de texto y se lo pasamos al mockup
    std::vector<std::string>  *dataLines = new std::vector<std::string>();
    dataLines->push_back(std::string("Wifi_01,Pass01\n"));
    dataLines->push_back(std::string("Wifi_02,Pass02\n"));
    dataLines->push_back(std::string("Wifi_03,Pass03\n"));
    sdManager->dataLines = dataLines;
    size_t vectorSize = dataLines->size();

    //Cuando se inicializa hace un delete de dataLines
    WiFiConfiguration wifiConfiguration = WiFiConfiguration(sdManager);
    
    EXPECT_EQ(wifiConfiguration.getConfiguredNetworks(), vectorSize);

    delete sdManager;
}