#ifndef GPS_h
#define GPS_h

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <interfaces/IGPSController.h>
#include <StringTokenizer.h>

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
    float latitud = 0;
    float longitud = 0;
    bool N = true;
    bool W = true;
    void parsearTiempo(std::string tiempo, int *horaDia, int *minutoMes, int *sengundoAnio);

public:
    GPS(IGPSController *GPSController);
    void actualizar();
    int getHora();
    int getMinuto();
    int getSegundo();
    int getDia();
    int getMes();
    int getAnio();
    float getLatitud();
    float getLongitud();
    bool isN();
    bool isW();
    ~GPS();
};

#endif