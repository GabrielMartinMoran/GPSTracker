#include <interfaces/IGPSController.h>
#include <string>
#include <Arduino.h>
#include <HardwareSerial.h>

class GPSController : public IGPSController
{
private:
    HardwareSerial uart = HardwareSerial(2);

public:
    GPSController();
    ~GPSController();
    std::string getInformation();
    bool isDataWaiting();
};
