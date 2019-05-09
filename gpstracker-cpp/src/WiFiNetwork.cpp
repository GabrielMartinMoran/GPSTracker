#include <WiFiNetwork.h>

WiFiNetwork::WiFiNetwork(std::string SSID, std::string password){
    this->SSID = SSID;
    this->password = password;
}

std::string WiFiNetwork::toString(){
    return "SSID: " + SSID + ", Password: " + password;
}

std::string WiFiNetwork::toCSVLine(){
    return SSID + "," + password;
}

std::string WiFiNetwork::getSSID(){
    return SSID;
}

std::string WiFiNetwork::getPassword(){
    return password;
}