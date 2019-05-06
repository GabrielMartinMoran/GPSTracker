#ifndef GPS_h
#define GPS_h

#include <iostream>
#include "GPSControllerMockup.h"
#include "StringTokenizer.h"

class GPS
{
private:
    GPSControllerMockup *controladorGPSMockup;
    uint8_t hora = 0;
    uint8_t minuto = 0;
    uint8_t segundo = 0;
    uint8_t dia = 0;
    uint8_t mes = 0;
    uint8_t anio = 0;
    float latitud = 0;
    float longitud = 0;
    bool N = true;
    bool W = true;
    void parsearTiempo(std::string tiempo, uint8_t *horaDia, uint8_t *minutoMes, uint8_t *sengundoAnio);

public:
    GPS(GPSControllerMockup *controladorGPSMockup);
    void actualizar();
    uint8_t getHora();
    uint8_t getMinuto();
    uint8_t getSegundo();
    uint8_t getDia();
    uint8_t getMes();
    uint8_t getAnio();
    ~GPS();
};

#endif