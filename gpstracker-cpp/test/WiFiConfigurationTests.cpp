#include <gtest/gtest.h>
#include <SDManagerMockup.h>
#include <WiFiConfiguration.h>
#include <iostream>

TEST(WiFiConfiguration, getConfiguredNetworks)
{
    SDManagerMockup *sdManager = new SDManagerMockup();
    
    //Llenamos un vector con lineas de texto y se lo pasamos al mockup
    std::vector<std::string>  *dataLines = new std::vector<std::string>();
    dataLines->push_back(std::string("Wifi_01,Pass01"));
    dataLines->push_back(std::string("Wifi_02,Pass02"));
    dataLines->push_back(std::string("Wifi_03,Pass03"));
    sdManager->dataLines = dataLines;
    size_t vectorSize = dataLines->size();

    //Cuando se inicializa hace un delete de dataLines
    WiFiConfiguration wifiConfiguration = WiFiConfiguration(sdManager);
    
    EXPECT_EQ(wifiConfiguration.getConfiguredNetworks(), vectorSize);

    delete sdManager;
}

TEST(WiFiConfiguration, getNetworkAtPosition)
{
    SDManagerMockup *sdManager = new SDManagerMockup();
    
    //Llenamos un vector con lineas de texto y se lo pasamos al mockup
    std::vector<std::string>  *dataLines = new std::vector<std::string>();
    dataLines->push_back(std::string("Wifi_01,Pass01"));
    dataLines->push_back(std::string("Wifi_02,Pass02"));
    sdManager->dataLines = dataLines;
    size_t vectorSize = dataLines->size();

    //Cuando se inicializa hace un delete de dataLines
    WiFiConfiguration wifiConfiguration = WiFiConfiguration(sdManager);
    
    EXPECT_EQ(wifiConfiguration.getNetworkAtPosition(1)->SSID, "Wifi_02");
    EXPECT_EQ(wifiConfiguration.getNetworkAtPosition(1)->password, "Pass02");

    delete sdManager;
}

TEST(WiFiConfiguration, removeNetwork)
{
    SDManagerMockup *sdManager = new SDManagerMockup();
    
    //Llenamos un vector con lineas de texto y se lo pasamos al mockup
    std::vector<std::string>  *dataLines = new std::vector<std::string>();
    dataLines->push_back(std::string("Wifi_01,Pass01"));
    dataLines->push_back(std::string("Wifi_02,Pass02"));
    sdManager->dataLines = dataLines;
    size_t vectorSize = dataLines->size();

    //Cuando se inicializa hace un delete de dataLines
    WiFiConfiguration wifiConfiguration = WiFiConfiguration(sdManager);
    wifiConfiguration.removeNetwork(0);
    
    EXPECT_EQ(wifiConfiguration.getConfiguredNetworks(), vectorSize - 1);
    EXPECT_EQ(wifiConfiguration.getNetworkAtPosition(0)->SSID, "Wifi_02");
    EXPECT_EQ(wifiConfiguration.getNetworkAtPosition(0)->password, "Pass02");

    delete sdManager;
}

TEST(WiFiConfiguration, addNetwork)
{
    SDManagerMockup *sdManager = new SDManagerMockup();
    
    //Llenamos un vector con lineas de texto y se lo pasamos al mockup
    std::vector<std::string>  *dataLines = new std::vector<std::string>();
    dataLines->push_back(std::string("Wifi_01,Pass01"));
    dataLines->push_back(std::string("Wifi_02,Pass02"));
    sdManager->dataLines = dataLines;
    size_t vectorSize = dataLines->size();

    //Cuando se inicializa hace un delete de dataLines
    WiFiConfiguration wifiConfiguration = WiFiConfiguration(sdManager);
    wifiConfiguration.addNetwork("Wifi_03", "Pass03");
    
    EXPECT_EQ(wifiConfiguration.getConfiguredNetworks(), vectorSize + 1);
    EXPECT_EQ(wifiConfiguration.getNetworkAtPosition(vectorSize)->SSID, "Wifi_03");
    EXPECT_EQ(wifiConfiguration.getNetworkAtPosition(vectorSize)->password, "Pass03");

    delete sdManager;
}

TEST(WiFiConfiguration, addNetworkFromCSVLine)
{
    SDManagerMockup *sdManager = new SDManagerMockup();
    
    //Llenamos un vector con lineas de texto y se lo pasamos al mockup
    std::vector<std::string>  *dataLines = new std::vector<std::string>();
    dataLines->push_back(std::string("Wifi_01,Pass01"));
    dataLines->push_back(std::string("Wifi_02,Pass02"));
    sdManager->dataLines = dataLines;
    size_t vectorSize = dataLines->size();

    //Cuando se inicializa hace un delete de dataLines
    WiFiConfiguration wifiConfiguration = WiFiConfiguration(sdManager);
    wifiConfiguration.addNetworkFromCSVLine("Wifi_03,Pass03");
    
    EXPECT_EQ(wifiConfiguration.getConfiguredNetworks(), vectorSize + 1);
    EXPECT_EQ(wifiConfiguration.getNetworkAtPosition(vectorSize)->SSID, "Wifi_03");
    EXPECT_EQ(wifiConfiguration.getNetworkAtPosition(vectorSize)->password, "Pass03");

    delete sdManager;
}

TEST(WiFiConfiguration, deleteConfigurationFile)
{
    SDManagerMockup *sdManager = new SDManagerMockup();
    std::vector<std::string>  *dataLines = new std::vector<std::string>();
    dataLines->push_back(std::string("Wifi_01,Pass01"));
    sdManager->dataLines = dataLines;

    WiFiConfiguration wifiConfiguration = WiFiConfiguration(sdManager);

    wifiConfiguration.deleteConfigurationFile();

    EXPECT_EQ(sdManager->deletedFilePath, WIFI_CONFIGURATION_FILENAME);

    delete sdManager;
}

TEST(WiFiConfiguration, listNetworks)
{
    SDManagerMockup *sdManager = new SDManagerMockup();
    
    //Llenamos un vector con lineas de texto y se lo pasamos al mockup
    std::vector<std::string>  *dataLines = new std::vector<std::string>();
    dataLines->push_back(std::string("Wifi_01,Pass01"));
    dataLines->push_back(std::string("Wifi_02,Pass02"));
    dataLines->push_back(std::string("Wifi_03,Pass03"));
    sdManager->dataLines = dataLines;

    //Cuando se inicializa hace un delete de dataLines
    WiFiConfiguration wifiConfiguration = WiFiConfiguration(sdManager);
    
    EXPECT_EQ(wifiConfiguration.listNetworks(), std::string("Wifi_01,Wifi_02,Wifi_03"));

    delete sdManager;
}

TEST(WiFiConfiguration, deleteNetwork)
{
    SDManagerMockup *sdManager = new SDManagerMockup();
    
    //Llenamos un vector con lineas de texto y se lo pasamos al mockup
    std::vector<std::string>  *dataLines = new std::vector<std::string>();
    dataLines->push_back(std::string("Wifi_01,Pass01"));
    dataLines->push_back(std::string("Wifi_02,Pass02"));
    sdManager->dataLines = dataLines;
    size_t vectorSize = dataLines->size();

    //Cuando se inicializa hace un delete de dataLines
    WiFiConfiguration wifiConfiguration = WiFiConfiguration(sdManager);
    wifiConfiguration.deleteNetwork("Wifi_01");
    
    EXPECT_EQ(wifiConfiguration.getConfiguredNetworks(), vectorSize - 1);
    EXPECT_EQ(wifiConfiguration.getNetworkAtPosition(0)->SSID, "Wifi_02");
    EXPECT_EQ(wifiConfiguration.getNetworkAtPosition(0)->password, "Pass02");

    delete sdManager;
}