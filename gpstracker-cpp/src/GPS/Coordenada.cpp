#include <GPS/Coordenada.h>

Coordenada::Coordenada(double latitud, double longitud){
    if(latitud > 180 || latitud < -180 || longitud > 180 || longitud < -180){
        throw InvalidCoordinate();
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