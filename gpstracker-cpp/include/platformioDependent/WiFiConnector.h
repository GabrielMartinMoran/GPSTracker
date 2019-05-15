#ifndef WiFiConnector_h
#define WiFiConnector_h

#include <interfaces/IWiFiConnector.h>
#include <interfaces/IWiFiConfiguration.h>
#include <WiFiNetwork.h>
#include <WiFi.h>
#include <Arduino.h>
#include <iostream>

#define MAX_CONNECTION_RETRIES 20
#define TIME_TO_WAIT_BEFORE_RETRY 500

class WiFiConnector : public IWiFiConnector
{
private:
    bool connected;
    IWiFiConfiguration *wifiConfiguration;
    void tryToConnectToAnAvaliableNetwork();

public:
    WiFiConnector(IWiFiConfiguration *wifiConfiguration);
    bool connect(std::string SSID, std::string password);
    void disconnect();
    std::vector<std::string> getAvaliableNetworks();
    bool isNetworkAvaliable(std::string SSID);
    bool isConnected();
    void beginConnectionLoop();
};

#endif