#ifndef SerialController_h
#define SerialController_h

#include <interfaces/ISerialController.h>
#include <Arduino.h>
#include <iostream>

#define SERIAL_BAUDS 115200

class SerialController : public ISerialController
{
public:
    SerialController();
    void println(std::string data);
    void println(int data);
    void print(std::string data);
    void print(int data);
};

#endif