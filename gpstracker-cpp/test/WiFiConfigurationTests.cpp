#include <gtest/gtest.h>
#include <SDManagerMockup.h>
#include <WiFiConfiguration.h>
#include <iostream>

TEST(WiFiConfiguration, getConfiguredNetworks)
{
    SDManagerMockup *sdManager = new SDManagerMockup();

    //Llenamos un vector con lineas de texto y se lo pasamos al mockup
    std::vector<std::string> *dataLines = new std::vector<std::string>();
    dataLines->push_back(std::string("Wifi_01,Pass01"));
    dataLines->push_back(std::string("Wifi_02,Pass02"));
    dataLines->push_back(std::string("Wifi_03,Pass03"));
    sdManager->dataLines = dataLines;
    size_t vectorSize = dataLines->size();

    //Cuando se inicializa hace un delete de dataLines
    WiFiConfiguration wifiConfiguration = WiFiConfiguration(sdManager);
    size_t obtainedNetowks = wifiConfiguration.getConfiguredNetworks();

    EXPECT_EQ(obtainedNetowks, vectorSize);

    delete sdManager;
}

TEST(WiFiConfiguration, getNetworkAtPosition)
{
    SDManagerMockup *sdManager = new SDManagerMockup();

    //Llenamos un vector con lineas de texto y se lo pasamos al mockup
    std::vector<std::string> *dataLines = new std::vector<std::string>();
    dataLines->push_back(std::string("Wifi_01,Pass01"));
    dataLines->push_back(std::string("Wifi_02,Pass02"));
    sdManager->dataLines = dataLines;
    size_t vectorSize = dataLines->size();

    //Cuando se inicializa hace un delete de dataLines
    WiFiConfiguration wifiConfiguration = WiFiConfiguration(sdManager);

    WiFiNetwork *network = wifiConfiguration.getNetworkAtPosition(1);

    EXPECT_EQ(network->getSSID(), "Wifi_02");
    EXPECT_EQ(network->getPassword(), "Pass02");

    delete sdManager;
}

TEST(WiFiConfiguration, removeNetwork)
{
    SDManagerMockup *sdManager = new SDManagerMockup();

    //Llenamos un vector con lineas de texto y se lo pasamos al mockup
    std::vector<std::string> *dataLines = new std::vector<std::string>();
    dataLines->push_back(std::string("Wifi_01,Pass01"));
    dataLines->push_back(std::string("Wifi_02,Pass02"));
    sdManager->dataLines = dataLines;
    size_t vectorSize = dataLines->size();

    //Cuando se inicializa hace un delete de dataLines
    WiFiConfiguration wifiConfiguration = WiFiConfiguration(sdManager);
    wifiConfiguration.removeNetwork(0);

    EXPECT_EQ(wifiConfiguration.getConfiguredNetworks(), vectorSize - 1);
    EXPECT_EQ(wifiConfiguration.getNetworkAtPosition(0)->getSSID(), "Wifi_02");
    EXPECT_EQ(wifiConfiguration.getNetworkAtPosition(0)->getPassword(), "Pass02");

    delete sdManager;
}

TEST(WiFiConfiguration, addNetwork)
{
    SDManagerMockup *sdManager = new SDManagerMockup();

    //Llenamos un vector con lineas de texto y se lo pasamos al mockup
    std::vector<std::string> *dataLines = new std::vector<std::string>();
    dataLines->push_back(std::string("Wifi_01,Pass01"));
    dataLines->push_back(std::string("Wifi_02,Pass02"));
    sdManager->dataLines = dataLines;
    size_t vectorSize = dataLines->size();

    //Cuando se inicializa hace un delete de dataLines
    WiFiConfiguration wifiConfiguration = WiFiConfiguration(sdManager);
    wifiConfiguration.addNetwork("Wifi_03", "Pass03");
    std::string writtenFile = sdManager->writtenFile;

    EXPECT_EQ(wifiConfiguration.getConfiguredNetworks(), vectorSize + 1);
    EXPECT_EQ(wifiConfiguration.getNetworkAtPosition(vectorSize)->getSSID(), "Wifi_03");
    EXPECT_EQ(wifiConfiguration.getNetworkAtPosition(vectorSize)->getPassword(), "Pass03");
    EXPECT_EQ(writtenFile, "Wifi_01,Pass01\nWifi_02,Pass02\nWifi_03,Pass03\n");

    delete sdManager;
}

TEST(WiFiConfiguration, addNetwork_multiple_times)
{
    SDManagerMockup *sdManager = new SDManagerMockup();

    //Llenamos un vector con lineas de texto y se lo pasamos al mockup
    std::vector<std::string> *dataLines = new std::vector<std::string>();
    dataLines->push_back(std::string("Wifi_01,Pass01"));
    sdManager->dataLines = dataLines;

    //Cuando se inicializa hace un delete de dataLines
    WiFiConfiguration wifiConfiguration = WiFiConfiguration(sdManager);
    wifiConfiguration.addNetwork("Wifi_02", "Pass02");
    wifiConfiguration.addNetwork("Wifi_03", "Pass03");
    wifiConfiguration.addNetwork("Wifi_04", "Pass04");
    wifiConfiguration.addNetwork("Wifi_05", "Pass05");
    std::string writtenFile = sdManager->writtenFile;

    EXPECT_EQ(wifiConfiguration.getConfiguredNetworks(), 5);
    EXPECT_EQ(wifiConfiguration.getNetworkAtPosition(2)->getSSID(), "Wifi_03");
    EXPECT_EQ(wifiConfiguration.getNetworkAtPosition(2)->getPassword(), "Pass03");
    EXPECT_EQ(wifiConfiguration.getNetworkAtPosition(4)->getSSID(), "Wifi_05");
    EXPECT_EQ(wifiConfiguration.getNetworkAtPosition(4)->getPassword(), "Pass05");
    EXPECT_EQ(writtenFile, "Wifi_01,Pass01\nWifi_02,Pass02\nWifi_03,Pass03\nWifi_04,Pass04\nWifi_05,Pass05\n");

    delete sdManager;
}

TEST(WiFiConfiguration, addNetworkFromCSVLine)
{
    SDManagerMockup *sdManager = new SDManagerMockup();

    //Llenamos un vector con lineas de texto y se lo pasamos al mockup
    std::vector<std::string> *dataLines = new std::vector<std::string>();
    dataLines->push_back(std::string("Wifi_01,Pass01"));
    dataLines->push_back(std::string("Wifi_02,Pass02"));
    sdManager->dataLines = dataLines;
    size_t vectorSize = dataLines->size();

    //Cuando se inicializa hace un delete de dataLines
    WiFiConfiguration wifiConfiguration = WiFiConfiguration(sdManager);
    wifiConfiguration.addNetworkFromCSVLine("Wifi_03,Pass03");

    EXPECT_EQ(wifiConfiguration.getConfiguredNetworks(), vectorSize + 1);
    EXPECT_EQ(wifiConfiguration.getNetworkAtPosition(vectorSize)->getSSID(), "Wifi_03");
    EXPECT_EQ(wifiConfiguration.getNetworkAtPosition(vectorSize)->getPassword(), "Pass03");

    delete sdManager;
}

TEST(WiFiConfiguration, deleteConfigurationFile)
{
    SDManagerMockup *sdManager = new SDManagerMockup();
    std::vector<std::string> *dataLines = new std::vector<std::string>();
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
    std::vector<std::string> *dataLines = new std::vector<std::string>();
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
    std::vector<std::string> *dataLines = new std::vector<std::string>();
    dataLines->push_back(std::string("Wifi_01,Pass01"));
    dataLines->push_back(std::string("Wifi_02,Pass02"));
    sdManager->dataLines = dataLines;
    size_t vectorSize = dataLines->size();

    //Cuando se inicializa hace un delete de dataLines
    WiFiConfiguration wifiConfiguration = WiFiConfiguration(sdManager);
    wifiConfiguration.deleteNetwork("Wifi_01");

    EXPECT_EQ(wifiConfiguration.getConfiguredNetworks(), vectorSize - 1);
    EXPECT_EQ(wifiConfiguration.getNetworkAtPosition(0)->getSSID(), "Wifi_02");
    EXPECT_EQ(wifiConfiguration.getNetworkAtPosition(0)->getPassword(), "Pass02");

    delete sdManager;
}

TEST(WiFiConfiguration, getNetwork)
{
    SDManagerMockup *sdManager = new SDManagerMockup();

    //Llenamos un vector con lineas de texto y se lo pasamos al mockup
    std::vector<std::string> *dataLines = new std::vector<std::string>();
    dataLines->push_back(std::string("Wifi_01,Pass01"));
    dataLines->push_back(std::string("Wifi_02,Pass02"));
    sdManager->dataLines = dataLines;
    size_t vectorSize = dataLines->size();

    //Cuando se inicializa hace un delete de dataLines
    WiFiConfiguration wifiConfiguration = WiFiConfiguration(sdManager);

    WiFiNetwork *network = wifiConfiguration.getNetwork("Wifi_02");

    EXPECT_EQ(network->getSSID(), "Wifi_02");
    EXPECT_EQ(network->getPassword(), "Pass02");

    delete sdManager;
}

TEST(WiFiConfiguration, getNetwork_that_not_exists)
{
    SDManagerMockup *sdManager = new SDManagerMockup();

    //Llenamos un vector con lineas de texto y se lo pasamos al mockup
    std::vector<std::string> *dataLines = new std::vector<std::string>();
    dataLines->push_back(std::string("Wifi_01,Pass01"));
    dataLines->push_back(std::string("Wifi_02,Pass02"));
    sdManager->dataLines = dataLines;
    size_t vectorSize = dataLines->size();

    //Cuando se inicializa hace un delete de dataLines
    WiFiConfiguration wifiConfiguration = WiFiConfiguration(sdManager);

    WiFiNetwork *network = wifiConfiguration.getNetwork("Wifi_03");

    EXPECT_EQ(network, nullptr);

    delete sdManager;
}