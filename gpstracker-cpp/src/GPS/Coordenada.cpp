#include <GPS/Coordenada.h>

Coordenada::Coordenada(double latitud, double longitud) : latitud(latitud), longitud(longitud) {}

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