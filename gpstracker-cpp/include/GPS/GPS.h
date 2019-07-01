#ifndef GPS_h
#define GPS_h

#include <iostream>
#include <interfaces/IGPSController.h>
#include <utils/DistanceCalculator.h>
#include <GPS/GPSData.h>

class GPS
{
private:
    IGPSController *GPSController = nullptr;
    GPSData *gpsData = nullptr;
    GPSData *gpsDataBuffer = nullptr;
    bool posicionValida(GPSData *gpsData);
    double metrosEntrePuntos;
    unsigned int posicionesInvariadas = 0;
    unsigned int maxPosicionesInvariadas = 10;

public:
    GPS(IGPSController *GPSController, double metrosEntrePuntos);
    bool actualizado();
    GPSData *getGPSData();
    ~GPS();
};

#endif