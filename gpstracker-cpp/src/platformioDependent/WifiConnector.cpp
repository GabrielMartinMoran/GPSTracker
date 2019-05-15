#include <platformioDependent/WiFiConnector.h>

WiFiConnector::WiFiConnector(IWiFiConfiguration *wifiConfiguration)
{
    this->wifiConfiguration = wifiConfiguration;
    WiFi.mode(WIFI_STA);
    disconnect();
}

bool WiFiConnector::connect(std::string SSID, std::string password)
{
    Serial.println("WiFi module is trying to connect to:");
    Serial.print("SSID: ");
    Serial.println(SSID.c_str());
    Serial.print("Password: ");
    Serial.println(password.c_str());
    disconnect();
    delay(500);

    WiFi.begin(SSID.c_str(), password.c_str());
    byte intentos = 0;
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(TIME_TO_WAIT_BEFORE_RETRY);
        Serial.print(".");
        intentos++;
        if (intentos > MAX_CONNECTION_RETRIES)
        {
            Serial.println("\nCould not stablish WiFi connection");
            connected = false;
            return false;
        }
    }
    Serial.println("\nWiFi connection stablished successfully!");
    connected = true;
    return true;
}

std::vector<std::string> WiFiConnector::getAvaliableNetworks()
{
    byte networkNumbers = WiFi.scanNetworks();
    std::vector<std::string> networks = std::vector<std::string>();
    byte actualNetwork = 0;
    while (actualNetwork < networkNumbers)
    {
        networks.push_back(WiFi.SSID(actualNetwork).c_str());
        actualNetwork++;
    }
    return networks;
}

void WiFiConnector::disconnect()
{
    WiFi.disconnect();
    connected = false;
}

bool WiFiConnector::isNetworkAvaliable(std::string SSID)
{
    byte networkNumbers = WiFi.scanNetworks();
    byte actualNetwork = 0;
    while (actualNetwork < networkNumbers)
    {
        if (WiFi.SSID(actualNetwork).c_str() == SSID.c_str())
        {
            return true;
        }
        actualNetwork++;
    }
    return false;
}

bool WiFiConnector::isConnected()
{
    return connected;
}

void WiFiConnector::beginConnectionLoop()
{
    while(true){
        if(WiFi.status() != WL_CONNECTED){
            connected = false;
            Serial.println("> EL WIFI NO ESTA CONECTADO!");
            tryToConnectToAnAvaliableNetwork();
        }    
        delay(200);
    }
}

void WiFiConnector::tryToConnectToAnAvaliableNetwork(){
    std::vector<std::string> avaliableNetworks = getAvaliableNetworks();
    for (size_t i = 0; i < avaliableNetworks.size(); i++)
    {
        std::string currSSID = avaliableNetworks.at(i);
        IWiFiNetwork *currNetwork = wifiConfiguration->getNetwork(currSSID);
        if(currNetwork != nullptr){
            bool couldConnect = connect(currNetwork->getSSID(), currNetwork->getPassword());
            if(couldConnect){
                return;
            }
        }
    }
    
}