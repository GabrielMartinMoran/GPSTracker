#include <WiFiNetwork.h>

WiFiNetwork::WiFiNetwork(String SSID, String password){
    this->SSID = SSID;
    this->password = password;
}

String WiFiNetwork::toString(){
    return "SSID: " + SSID + ", Password: " + password;
}