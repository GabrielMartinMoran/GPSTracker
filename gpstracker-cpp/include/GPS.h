#ifndef GPS_h
#define GPS_h

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <interfaces/IGPSController.h>
#include <StringTokenizer.h>
#include <Haversine.h>

class GPS
{
private:
    IGPSController *GPSController;
    int hora = 0;
    int minuto = 0;
    int segundo = 0;
    int dia = 0;
    int mes = 0;
    int anio = 0;
    double latitud = 0;
    double longitud = 0;
    void parsearTiempo(std::string tiempo, int *horaDia, int *minutoMes, int *sengundoAnio);
    bool posicionValida(double latitud, double longitud);
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