#include <WiFiConnector.h>

WifiConnector::WifiConnector()
{
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
}

void WifiConnector::connect(char *SSID, char *password)
{
    WiFi.begin(SSID, password);
    byte intentos = 0;
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
        intentos++;
        if (intentos > MAX_CONNECTION_RETRIES)
        {
            Serial.println("\nCould not stablish WiFi connection");
            return;
        }
    }
    Serial.println("\nWiFi connection stablished successfully!");
    return;
}

void WifiConnector::getAvaliableNetworks()
{
    Serial.println("Avaliable Networks:");
    byte networkNumbers = WiFi.scanNetworks();
    byte actualNetwork = 0;
    while (actualNetwork < networkNumbers)
    {
        Serial.println(WiFi.SSID(actualNetwork));
        actualNetwork++;
    }
}