#include <iostream>
#include <Arduino.h>
#include <platformDependent/GPSController.h>
#include <GPS/GPS.h>

#define UART_USB 0
#define UART_GPS 2
#define DECIMALES 10

HardwareSerial *usb;
GPSController *gpsController;
GPS *gps;

void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);
    usb = new HardwareSerial(UART_USB);
    gpsController = new GPSController(UART_GPS);
    usb->begin(115200);
    gps = new GPS(gpsController, 2);
}

void loop()
{
    if (gps->updated())
    {
        usb->print("Raw Data: ");
        usb->println(gps->getGPSData().getRawData().c_str());
        usb->print("Latitud: ");
        usb->println(gps->getGPSData().getCoordinate().getLatitude(), DECIMALES);
        usb->print("Longitud: ");
        usb->println(gps->getGPSData().getCoordinate().getLongitude(), DECIMALES);
        usb->print("Hora: ");
        usb->print(gps->getGPSData().getDateTime().getHour());
        usb->print(":");
        usb->print(gps->getGPSData().getDateTime().getMinute());
        usb->print(":");
        usb->println(gps->getGPSData().getDateTime().getSecond());
        usb->print("Fecha: ");
        usb->print(gps->getGPSData().getDateTime().getDay());
        usb->print("/");
        usb->print(gps->getGPSData().getDateTime().getMonth());
        usb->print("/");
        usb->println(gps->getGPSData().getDateTime().getYear());
        usb->println();
    }

    delay(100);
}