#include <GPS/GPS.h>

GPS::GPS(IGPSController *GPSController, unsigned int metrosEntrePuntos) : GPSController(GPSController), metrosEntrePuntos(metrosEntrePuntos)
{
}

bool GPS::posicionValida(GPSData *gpsData)
{
    return haversine_m(this->gpsData->getCoordenada().getLatitud(), this->gpsData->getCoordenada().getLongitud(),
                       gpsData->getCoordenada().getLatitud(), gpsData->getCoordenada().getLongitud()) > this->metrosEntrePuntos;
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
                this->posicionesInvariadas = 0;
                this->gpsData = nuevo;
                return true;
            }

            if (posicionValida(nuevo))
            {
                this->posicionesInvariadas = 0;
                delete this->gpsData;
                this->gpsData = nuevo;
                return true;
            }

            if (this->posicionesInvariadas < this->maxPosicionesInvariadas)
            {
                this->posicionesInvariadas++;
            }
            else
            {
                this->gpsData->inmovil();
            }
        }

        delete nuevo;
    }
    return false;
}

GPSData *GPS::getGPSData()
{
    return this->gpsData;
}

GPS::~GPS()
{
    delete this->gpsData;
}
