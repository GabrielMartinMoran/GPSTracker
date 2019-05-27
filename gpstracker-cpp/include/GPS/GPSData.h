#ifndef GPSData_h
#define GPSData_h

#include <string>
#include <stdio.h>
#include <cmath>
#include <utils/StringTokenizer.h>
#include <utils/StringToNumber.h>
#include <GPS/DateTime.h>
#include <GPS/Coordenada.h>

class GPSData
{
private:
    DateTime *date_time = new DateTime(1,1,0,0,0,0);
    Coordenada *coordenada = new Coordenada(0,0);
    void parsearTiempo(std::string *tiempo, unsigned int *horaDia, unsigned int *minutoMes, unsigned int *sengundoAnio);
    double parsearCoordenada(std::string coordenada);
    bool valido = false;
    std::string rawData;

public:
    GPSData(std::string data);
    DateTime dateTime();
    Coordenada getCoordenada();
    bool isValido();
    std::string getRawData();
    std::string getNormalizedData();
    ~GPSData();
};
#endif