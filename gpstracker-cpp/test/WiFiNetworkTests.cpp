#include <gtest/gtest.h>
#include <WiFiNetwork.h>

TEST(WiFiNetwork, toString)
{
    std::string SSID = "Test SSID";
    std::string password = "TestPassword";
    WiFiNetwork wifiNetwork = WiFiNetwork("Test SSID", "TestPassword");

    EXPECT_TRUE(wifiNetwork.toString() == "SSID: Test SSID, Password: TestPassword");
}

TEST(WiFiNetwork, toCSVLine)
{
    std::string SSID = "Test SSID";
    std::string password = "TestPassword";
    WiFiNetwork wifiNetwork = WiFiNetwork("Test SSID", "TestPassword");
    
    EXPECT_TRUE(wifiNetwork.toCSVLine() == "Test SSID,TestPassword");
}