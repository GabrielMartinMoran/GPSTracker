#ifndef ISerialController_h
#define ISerialController_h

#include <iostream>

class ISerialController
{
public:
    virtual ~ISerialController() {}
    virtual void println(std::string data) = 0;
    virtual void println(int data) = 0;
    virtual void print(std::string data) = 0;
    virtual void print(int data) = 0;
};

#endif