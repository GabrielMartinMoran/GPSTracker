#include <platformioDependent/GPSController.h>

GPSController::GPSController(int uartNumber)
{
    this->uart = new HardwareSerial(uartNumber);
    this->uart->begin(9600);
}

std::string GPSController::getInformation()
{
    std::string sentencia = std::string(this->uart->readStringUntil('\r').c_str());
    this->uart->readStringUntil('\n');
    return sentencia;
}

bool GPSController::isDataWaiting()
{
    return this->uart->available() > 0;
}

GPSController::~GPSController()
{
}