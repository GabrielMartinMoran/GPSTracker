#include <GPS/GPS.h>

GPS::GPS(IGPSController *GPSController)
{
    this->GPSController = GPSController;
}

bool GPS::posicionValida(GPSData *gpsData)
{
    return haversine_m(this->gpsData->getCoordenada().getLatitud(), this->gpsData->getCoordenada().getLongitud(), gpsData->getCoordenada().getLatitud(), gpsData->getCoordenada().getLongitud()) > 2.5;
}

bool GPS::actualizado()
{
    while (this->GPSController->isDataWaiting())
    {
        GPSData *nuevo = new GPSData(this->GPSController->getInformation());
        if (nuevo->isValido())
        {
            if (posicionValida(nuevo))
            {
                delete this->gpsData;
                this->gpsData = nuevo;
                return true;
            }
        }
    }
    return false;
}

GPSData GPS::getGPSData()
{
    return *this->gpsData;
}

GPS::~GPS()
{
}
