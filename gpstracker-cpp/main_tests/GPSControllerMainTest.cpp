
#include <iostream>
#include <Arduino.h>

#include <platformioDependent/GPSController.h>
#include <HardwareSerial.h>

HardwareSerial usb = HardwareSerial(0);
GPSController gpsController = GPSController();

void setup()
{
    usb.begin(115200);
}

void loop()
{
    if (usb.availableForWrite())
    {
        if (gpsController.isDataWaiting())
        {
            usb.println(gpsController.getInformation().c_str());
        }
    }
    delay(100);
}