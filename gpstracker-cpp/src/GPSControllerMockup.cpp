#include "GPSControllerMockup.h"
#include <iostream>

GPSControllerMockup::GPSControllerMockup(){
    
}

GPSControllerMockup::GPSControllerMockup(int pinTX, int pinRX){
    this->pinTX = pinTX;
    this->pinRX = pinRX;
}

std::string GPSControllerMockup::getInformation()
{
    std::string command = "$GPRMC,081836,A,3751.65,S,14507.36,E,000.0,360.0,130998,011.3,E*62";
    return command;
}

GPSControllerMockup::~GPSControllerMockup(){

}