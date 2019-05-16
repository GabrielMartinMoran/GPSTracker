#include <GPS.h>

GPS::GPS(IGPSController *GPSController)
{
    this->GPSController = GPSController;
}

bool GPS::posicionValida(GPSData gpsData)
{
    return haversine_m(this->gpsData.getLatitud(), this->gpsData.getLongitud(), gpsData.getLatitud(), gpsData.getLongitud()) > 2.5;
}

void GPS::actualizar()
{
    std::string datos = this->GPSController->getInformation();
    GPSData nuevo = GPSData(datos);
    if(nuevo.isValido()){
        if(posicionValida(nuevo)){
            this->gpsData = nuevo;
        }
    }
}

int GPS::getHora()
{
    return this->gpsData.getHora();
}

int GPS::getMinuto()
{
    return this->gpsData.getMinuto();
}

int GPS::getSegundo()
{
    return this->gpsData.getSegundo();
}

int GPS::getDia()
{
    return this->gpsData.getDia();
}

int GPS::getMes()
{
    return this->gpsData.getMes();
}

int GPS::getAnio()
{
    return this->gpsData.getAnio();
}

double GPS::getLatitud()
{
    return this->gpsData.getLatitud();
}
double GPS::getLongitud()
{
    return this->gpsData.getLongitud();
}

GPS::~GPS()
{
}
