#ifndef GPSData_h
#define GPSData_h

#include <string>
#include <stdio.h>
#include <cmath>
#include <utils/StringTokenizer.h>
#include <utils/StringToNumber.h>
#include <GPS/DateTime.h>
#include <GPS/Coordenada.h>
#include <exceptions/InvalidReadGPSDataException.ex>

class GPSData
{
private:
    DateTime *date_time = nullptr;
    Coordenada *coordenada = nullptr;
    void parsearTiempo(std::string tiempo, unsigned int *horaDia, unsigned int *minutoMes, unsigned int *sengundoAnio);
    double parsearCoordenada(std::string coordenada);
    std::string rawData;
    bool isInmovil();
    bool _inmovil = false;
    void invalidar();
    std::string calculateChecksum(std::string sentencias);

public:
    GPSData(std::string data);
    DateTime dateTime();
    Coordenada getCoordenada();
    bool isValido();
    void inmovil();
    std::string getRawData();
    std::string getNormalizedData();
    ~GPSData();
};
#endif