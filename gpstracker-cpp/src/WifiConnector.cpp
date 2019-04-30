#include <WiFiConnector.h>

WiFiConnector::WiFiConnector()
{
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
}

void WiFiConnector::connect(String SSID, String password)
{
    char _SSID[SSID.length() + 1];
    SSID.toCharArray(_SSID, SSID.length() + 1);
    char _password[password.length() + 1];
    password.toCharArray(_password, password.length() + 1);

    Serial.println("WiFi module is trying to connect to:");
    Serial.print("SSID: ");
    Serial.println(_SSID);
    Serial.print("Password: ");
    Serial.println(_password);

    WiFi.disconnect();
    delay(500);

    WiFi.begin(_SSID, _password);
    byte intentos = 0;
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(TIME_TO_WAIT_BEFORE_RETRY);
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

void WiFiConnector::getAvaliableNetworks()
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

bool WiFiConnector::isNetworkAvaliable(String SSID)
{
    byte networkNumbers = WiFi.scanNetworks();
    byte actualNetwork = 0;
    while (actualNetwork < networkNumbers)
    {
        if (WiFi.SSID(actualNetwork) == SSID)
        {
            return true;
        }
        actualNetwork++;
    }
    return false;
}