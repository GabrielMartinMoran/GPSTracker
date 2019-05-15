#include <GPS.h>

GPS::GPS(IGPSController *GPSController)
{
    this->GPSController = GPSController;
}

bool GPS::posicionValida(double latitud, double longitud){
    return haversine_km(latitud, longitud, this->latitud, this->longitud) > 0;
}

void GPS::actualizar()
{
    std::string datos = this->GPSController->getInformation();
    StringTokenizer tokens(datos, ",");
    if (tokens.nextToken() == "$GPRMC")
    {
        std::string tiempo = tokens.nextToken(); // 08:18:36 UTC
        parsearTiempo(tiempo, &(this->hora), &(this->minuto), &(this->segundo));
        if (tokens.nextToken() == std::string("A"))
        {
            this->latitud = ::atof(tokens.nextToken().c_str());
            if(tokens.nextToken() == std::string("S")){
                this->latitud *= -1;
            }
            this->longitud = ::atof(tokens.nextToken().c_str());
            if(tokens.nextToken() == std::string("E")){
                this->longitud *= -1;
            }
            tokens.nextToken();                     //Speed over ground, Knots
            tokens.nextToken();                     //Course Made Good, True
            std::string fecha = tokens.nextToken(); //13 Sep 1998
            parsearTiempo(fecha, &(this->dia), &(this->mes), &(this->anio));
            tokens.nextToken(); //Magnetic variation 20.3 deg East
            tokens.nextToken(); //mandatory checksum
        }
    }
}

void GPS::parsearTiempo(std::string tiempo, int *horaDia, int *minutoMes, int *sengundoAnio)
{
    *horaDia = atoi(tiempo.substr(0, 2).c_str());
    *minutoMes = atoi(tiempo.substr(2, 2).c_str());
    *sengundoAnio = atoi(tiempo.substr(4, 2).c_str());
}

int GPS::getHora()
{
    return this->hora;
}

int GPS::getMinuto()
{
    return this->minuto;
}

int GPS::getSegundo()
{
    return this->segundo;
}

int GPS::getDia()
{
    return this->dia;
}

int GPS::getMes()
{
    return this->mes;
}

int GPS::getAnio()
{
    return this->anio;
}

double GPS::getLatitud()
{
    return this->latitud;
}
double GPS::getLongitud()
{
    return this->longitud;
}

GPS::~GPS()
{
}
