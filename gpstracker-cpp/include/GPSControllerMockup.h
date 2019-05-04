#ifndef GPSControllerMockup_h
#define GPSControllerMockup_h

#include <iostream>

class GPSControllerMockup
{
private:
    int pinRX = 0;
    int pinTX = 0;

public:
    GPSControllerMockup(int pinTX, int pinRX);
    GPSControllerMockup();
    std::string getInformation();
    ~GPSControllerMockup();
};

#endif