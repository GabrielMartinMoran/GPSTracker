#ifndef GPS_h
#define GPS_h

#include <iostream>
#include <interfaces/IGPSController.h>
#include <utils/Haversine.h>
#include <GPS/GPSData.h>

class GPS
{
private:
    IGPSController *GPSController = nullptr;
    GPSData *gpsData = nullptr;
    bool posicionValida(GPSData *gpsData);

public:
    GPS(IGPSController *GPSController);
    bool actualizado(); //devuelve true si actualizo
    GPSData getGPSData();
    ~GPS();
};

#endif