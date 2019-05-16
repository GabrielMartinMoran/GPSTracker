#ifndef GPS_h
#define GPS_h

#include <iostream>
#include <interfaces/IGPSController.h>
#include <utils/Haversine.h>
#include <GPSData.h>

class GPS
{
private:
    IGPSController *GPSController;
    GPSData gpsData = GPSData(std::string(""));
    bool posicionValida(GPSData gpsData);
public:
    GPS(IGPSController *GPSController);
    void actualizar();
    int getHora();
    int getMinuto();
    int getSegundo();
    int getDia();
    int getMes();
    int getAnio();
    double getLatitud();
    double getLongitud();
    ~GPS();
};

#endif