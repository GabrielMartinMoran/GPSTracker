#include <interfaces/IGPSController.h>
#include <string>
#include <Arduino.h>
#include <SoftwareSerial.h>

class GPSController : public IGPSController
{
private:
    SoftwareSerial *gps;

public:
    GPSController(int pinTX, int pinRX);
    std::string getInformation() = 0;

    bool isDataWaiting() = 0;
    ~GPSController() {}
};
