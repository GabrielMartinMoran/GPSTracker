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
    bool validPosition(GPSData *gpsData);
    double metersBetweenPoints;
    unsigned int staticPositions = 0;
    unsigned int maxStaticPositions = 10;

public:
    GPS(IGPSController *GPSController, double metersBetweenPoints);
    bool updated();
    GPSData *getGPSData();
    ~GPS();
};

#endif