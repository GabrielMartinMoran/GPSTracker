#include <gtest/gtest.h>
#include <BluetoothServer.h>
#include <BluetoothMockup.h>
#include <WiFiConfigurationMockup.h>

TEST(BluetoothServer, onRequest)
{
    BluetoothMockup *bluetooth = new BluetoothMockup();
    WiFiConfigurationMockup *wifiConfiguration = new WiFiConfigurationMockup();

    BluetoothServer server = BluetoothServer(wifiConfiguration, bluetooth);

    server.onRequest("A");

    EXPECT_EQ(bluetooth->transmittedData, "200");

    delete bluetooth;
    delete wifiConfiguration;
}