#include <platformDependent/GPSController.h>

GPSController::GPSController(int uartNumber)
{
    this->uart = new HardwareSerial(uartNumber);
    this->uart->begin(9600);
}

std::string GPSController::getInformation()
{
    std::string sentence = std::string(this->uart->readStringUntil('\r').c_str());
    this->uart->readStringUntil('\n');
    Serial.println(sentence.c_str());
    return sentence;
}

bool GPSController::isWaitingData()
{
    return this->uart->available() > 0;
}

GPSController::~GPSController()
{
}