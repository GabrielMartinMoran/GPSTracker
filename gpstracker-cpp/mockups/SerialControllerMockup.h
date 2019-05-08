#ifndef SerialControllerMockup_h
#define SerialControllerMockup_h

#include <interfaces/ISerialController.h>
#include <iostream>

class SerialControllerMockup : public ISerialController
{
public:
    void println(std::string data)
    {
        std::cout << data << std::endl;
    };
    void println(int data)
    {
        std::cout << data << std::endl;
    }
    void print(std::string data)
    {
        std::cout << data;
    }
    void print(int data)
    {
        std::cout << data;
    }
};

#endif