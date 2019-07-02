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
    if (gps->actualizado())
    {
        usb->print("Raw Data: ");
        usb->println(gps->getGPSData().getRawData().c_str());
        usb->print("Latitud: ");
        usb->println(gps->getGPSData().getCoordenada().getLatitud(), DECIMALES);
        usb->print("Longitud: ");
        usb->println(gps->getGPSData().getCoordenada().getLongitud(), DECIMALES);
        usb->print("Hora: ");
        usb->print(gps->getGPSData().dateTime().getHora());
        usb->print(":");
        usb->print(gps->getGPSData().dateTime().getMinuto());
        usb->print(":");
        usb->println(gps->getGPSData().dateTime().getSegundo());
        usb->print("Fecha: ");
        usb->print(gps->getGPSData().dateTime().getDia());
        usb->print("/");
        usb->print(gps->getGPSData().dateTime().getMes());
        usb->print("/");
        usb->println(gps->getGPSData().dateTime().getAnio());
        usb->println();
    }

    delay(100);
}