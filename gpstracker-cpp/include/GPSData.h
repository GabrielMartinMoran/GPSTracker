#ifndef GPSData_h
#define GPSData_h

#include <string>
#include <utils/StringTokenizer.h>
#include <utils/StringToNumber.h>
#include <DateTime.h>

class GPSData
{
private:
    DateTime date_time = DateTime(0,0,0,0,0,0);
    double latitud = 0;
    double longitud = 0;
    void parsearTiempo(std::string tiempo, int *horaDia, int *minutoMes, int *sengundoAnio);
    double parsearCoordenada(std::string coordenada);
    bool valido = false;
    std::string rawData;

public:
    GPSData(std::string data);
    DateTime dateTime();
    double getLatitud();
    double getLongitud();
    bool isValido();
    std::string getRawData();
    ~GPSData();
};
#endif