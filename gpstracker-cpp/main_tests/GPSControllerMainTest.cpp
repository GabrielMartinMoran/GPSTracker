#include <iostream>
#include <Arduino.h>
#include <platformioDependent/GPSController.h>

#define uartUSB 0
#define uartGPS 2

HardwareSerial *usb;
GPSController *gpsController;
void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);
    usb = new HardwareSerial(uartUSB);
    gpsController = new GPSController(uartGPS);
    usb->begin(115200);
}

void loop()
{
    if (usb->availableForWrite())
    {
        if (gpsController->isDataWaiting())
        {
            digitalWrite(LED_BUILTIN, HIGH);
            usb->println(gpsController->getInformation().c_str());
            delay(100);
            digitalWrite(LED_BUILTIN, LOW);
        }
    }
    else
    {
        delay(100);
    }
}