#include <iostream>
#include <Arduino.h>
#include <platformioDependent/GPSController.h>
#include <GPS.h>

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
    gps = new GPS(gpsController);
}

void loop()
{
    if (gps->actualizado())
    {
        usb->print("Raw Data: ");
        usb->println(gps->getGPSData().getRawData().c_str());
        usb->print("Latitud: ");
        usb->println(gps->getGPSData().getLatitud(), DECIMALES);
        usb->print("Longitud: ");
        usb->println(gps->getGPSData().getLongitud(), DECIMALES);
        usb->print("Hora: ");
        usb->print(gps->getGPSData().getHora());
        usb->print(":");
        usb->print(gps->getGPSData().getMinuto());
        usb->print(":");
        usb->println(gps->getGPSData().getSegundo());
        usb->print("Fecha: ");
        usb->print(gps->getGPSData().getDia());
        usb->print("/");
        usb->print(gps->getGPSData().getMes());
        usb->print("/");
        usb->println(gps->getGPSData().getAnio());
        usb->println();
    }

    delay(100);
}