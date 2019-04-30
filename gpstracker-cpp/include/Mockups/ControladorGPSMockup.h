#ifndef ControladorGPSMockup_h
#define ControladorGPSMockup_h

#include <Arduino.h>

class ControladorGPSMockup
{
private:
    int pinRX = 0;
    int pinTX = 0;

public:
    ControladorGPSMockup(int pinTX, int pinRX);
    String leerInformacion();
    ~ControladorGPSMockup();
};

#endif