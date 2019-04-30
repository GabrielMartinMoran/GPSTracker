#include <WiFi.h>
#include <Arduino.h>

#define MAX_CONNECTION_RETRIES 10

class WifiConnector{
    public:
        WifiConnector();
        void connect(char *SSID, char *password);
        void getAvaliableNetworks();
};