#ifndef GPSData_h
#define GPSData_h

#include <string>
#include <utils/StringTokenizer.h>
#include <utils/StringToNumber.h>

class GPSData
{
private:
    int hora = 0;
    int minuto = 0;
    int segundo = 0;
    int dia = 0;
    int mes = 0;
    int anio = 0;
    float latitud = 0;
    float longitud = 0;
    void parsearTiempo(std::string tiempo, int *horaDia, int *minutoMes, int *sengundoAnio);
    bool valido = false;

public:
    GPSData(std::string data);
    int getHora();
    int getMinuto();
    int getSegundo();
    int getDia();
    int getMes();
    int getAnio();
    float getLatitud();
    float getLongitud();
    bool isValido();
    ~GPSData();
};
#endif