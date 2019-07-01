#include <gtest/gtest.h>
#include <BluetoothServer.h>
#include <BluetoothMockup.h>
#include <WiFiConfigurationMockup.h>
#include <SerialControllerMockup.h>


TEST(BluetoothServer, onRequest_DELETE_WIFI)
{
    BluetoothMockup *bluetooth = new BluetoothMockup();
    WiFiConfigurationMockup *wifiConfiguration = new WiFiConfigurationMockup();
    SerialControllerMockup *serialController = new SerialControllerMockup();

    BluetoothServer server = BluetoothServer(wifiConfiguration, bluetooth, serialController);

    server.onRequest("$DELETE_NETWORK$WiFi_01");

    EXPECT_EQ(wifiConfiguration->deletedNetowkSSID, "WiFi_01");

    delete bluetooth;
    delete wifiConfiguration;
    delete serialController;
}

TEST(BluetoothServer, onRequest_LIST_WIFI)
{
    BluetoothMockup *bluetooth = new BluetoothMockup();
    WiFiConfigurationMockup *wifiConfiguration = new WiFiConfigurationMockup();
    SerialControllerMockup *serialController = new SerialControllerMockup();

    BluetoothServer server = BluetoothServer(wifiConfiguration, bluetooth, serialController);

    wifiConfiguration->networksStrList = std::string("WiFi_01,WiFi_02,WiFi_03");

    server.onRequest("$LIST_NETWORKS$");

    EXPECT_EQ(bluetooth->transmittedData, wifiConfiguration->networksStrList);

    delete bluetooth;
    delete wifiConfiguration;
    delete serialController;
}

TEST(BluetoothServer, onRequest_ADD_WIFI)
{
    BluetoothMockup *bluetooth = new BluetoothMockup();
    WiFiConfigurationMockup *wifiConfiguration = new WiFiConfigurationMockup();
    SerialControllerMockup *serialController = new SerialControllerMockup();

    BluetoothServer server = BluetoothServer(wifiConfiguration, bluetooth, serialController);

    server.onRequest("$ADD_NETWORK$WiFi_01,Pass_01");

    EXPECT_EQ(wifiConfiguration->networkFromCSVLine, "WiFi_01,Pass_01");

    delete bluetooth;
    delete wifiConfiguration;
    delete serialController;
}