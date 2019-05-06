#ifndef SerialController_h
#define SerialController_h

#include <Arduino.h>
#include <iostream>

class SerialController {
    private:
        static bool isSerialInitialized;
        static void initializeSerial();
        static void initializeIfNeeded();
    public:
        static void println(std::string data);
        static void println(int data);
        static void print(std::string data);
        static void print(int data);
};

#endif