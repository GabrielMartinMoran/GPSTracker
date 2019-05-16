#include <platformioDependent/GPSController.h>

GPSController::GPSController(int pinRX, int pinTX)
{
    this->gps = new SoftwareSerial(pinRX, pinTX, false, 256);
    this->gps->begin(9600);
}

std::string GPSController::getInformation()
{
    char line[100];
    this->gps->readStringUntil('\n').toCharArray(line, 100);

    return std::string(line);
}

bool GPSController::isDataWaiting()
{
    return this->gps->available() > 0;
}

GPSController::~GPSController()
{
    delete gps;
}