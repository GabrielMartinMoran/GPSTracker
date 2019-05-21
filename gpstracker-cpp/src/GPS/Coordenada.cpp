#include <GPS/Coordenada.h>

Coordenada::Coordenada(double latitud, double longitud){
    if(latitud > 180 || latitud < -180){
        throw 1;
    }
    if(longitud > 180 || longitud < -180){
        throw 1;
    }
    this->latitud = latitud;
    this->longitud = longitud;
}

double Coordenada::getLatitud()
{
    return this->latitud;
}
double Coordenada::getLongitud()
{
    return this->longitud;
}

Coordenada::~Coordenada() {
}