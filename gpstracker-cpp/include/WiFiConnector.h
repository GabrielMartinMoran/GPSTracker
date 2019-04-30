#include <WiFi.h>
#include <Arduino.h>

#define MAX_CONNECTION_RETRIES 20
#define TIME_TO_WAIT_BEFORE_RETRY 500

class WiFiConnector
{
  public:
    WiFiConnector();
    void connect(String SSID, String password);
    void getAvaliableNetworks();
    bool isNetworkAvaliable(String SSID);
};