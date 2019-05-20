#include <platformioDependent/GPSController.h>

GPSController::GPSController()
{
    this->uart.begin(9600);
}

std::string GPSController::getInformation()
{
    char line[100];
    this->uart.readStringUntil('\n').toCharArray(line, 100);

    return std::string(line);
}

bool GPSController::isDataWaiting()
{
    return this->uart.available() > 0;
}

GPSController::~GPSController()
{
}