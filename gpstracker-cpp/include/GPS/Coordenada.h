#ifndef Coordenada_h
#define Coordenada_h

#include <exceptions/InvalidCoordinateException.ex>

class Coordenada
{
private:
    double latitud = 0;
    double longitud = 0;

public:
    Coordenada(double latitud, double longitud);
    double getLatitud();
    double getLongitud();
    ~Coordenada();
};
#endif