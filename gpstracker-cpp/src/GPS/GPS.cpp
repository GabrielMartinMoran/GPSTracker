#include <GPS/GPS.h>

GPS::GPS(IGPSController *GPSController)
{
    this->GPSController = GPSController;
}

bool GPS::posicionValida(GPSData *gpsData)
{
    return haversine_m(this->gpsData->getCoordenada().getLatitud(), this->gpsData->getCoordenada().getLongitud(), gpsData->getCoordenada().getLatitud(), gpsData->getCoordenada().getLongitud()) > METROS_ENTRE_PUNTOS;
}

bool GPS::actualizado()
{
    while (this->GPSController->isDataWaiting())
    {
        GPSData *nuevo = new GPSData(this->GPSController->getInformation());
        if (nuevo->isValido())
        {
            if (this->gpsData == nullptr)
            {
                this->gpsData = nuevo;
                return true;
            }
            else
            {
                if (posicionValida(nuevo))
                {
                    delete this->gpsData;
                    this->gpsData = nuevo;
                    return true;
                }
            }
        }
        delete nuevo;
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
