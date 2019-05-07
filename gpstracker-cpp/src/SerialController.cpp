#include <SerialController.h>

//Inicializamos asi el atributo estatico de la clase
bool SerialController::isSerialInitialized = false;

void SerialController::initializeSerial()
{
    Serial.begin(115200);
    isSerialInitialized = true;
}

void SerialController::initializeIfNeeded()
{
    if (!isSerialInitialized)
    {
        initializeSerial();
    }
}

void SerialController::println(std::string data)
{
    initializeIfNeeded();
    Serial.println(data.c_str());
}

void SerialController::println(int data)
{
    initializeIfNeeded();
    Serial.println(data);
}

void SerialController::print(std::string data)
{
    initializeIfNeeded();
    Serial.println(data.c_str());
}

void SerialController::print(int data)
{
    initializeIfNeeded();
    Serial.println(data);
}