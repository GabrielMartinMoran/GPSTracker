#include <gtest/gtest.h>
#include <SDManagerMockup.h>
#include <WiFiConfiguration.h>
#include <iostream>

TEST(WiFiConfiguration, getConfiguredNetworks)
{
    SDManagerMockup *sdManager = new SDManagerMockup();    
    WiFiConfiguration wifiConfiguration = WiFiConfiguration(sdManager);

    //Llenamos un vector con lineas de texto y se lo pasamos al mockup
    std::vector<std::string>  *dataLines = new std::vector<std::string>();
    dataLines->push_back(std::string("Wifi_01,Pass01"));
    dataLines->push_back(std::string("Wifi_02,Pass02"));
    dataLines->push_back(std::string("Wifi_03,Pass03"));
    wifiConfiguration->dataLines = dataLines;

    wifiConfiguration.loadConfiguration();    
    EXPECT_TRUE(wifiNetwork.getConfiguredNetworks() == dataLines->size());

    delete sdManager;
    delete dataLines;
}