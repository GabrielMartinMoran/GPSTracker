#include <interfaces/IGPSController.h>
#include <string>
#include <Arduino.h>
#include <HardwareSerial.h>

class GPSController : public IGPSController
{
private:
    HardwareSerial *uart;

public:
    GPSController(int uart);
    ~GPSController();
    std::string getInformation();
    bool isDataWaiting();
};
