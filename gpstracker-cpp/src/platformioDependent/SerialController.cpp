#include <platformioDependent/SerialController.h>

SerialController::SerialController()
{
    Serial.begin(SERIAL_BAUDS);
}

void SerialController::println(std::string data)
{
    Serial.println(data.c_str());
}

void SerialController::println(int data)
{
    Serial.println(data);
}

void SerialController::print(std::string data)
{
    Serial.println(data.c_str());
}

void SerialController::print(int data)
{
    Serial.println(data);
}