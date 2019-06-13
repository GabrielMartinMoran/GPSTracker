#include <GPS/GPS.h>

GPS::GPS(IGPSController *GPSController, unsigned int metrosEntrePuntos):GPSController(GPSController),metrosEntrePuntos(metrosEntrePuntos)
{
}

bool GPS::posicionValida(GPSData *gpsData)
{
    return haversine_m(this->gpsData->getCoordenada().getLatitud(), this->gpsData->getCoordenada().getLongitud(),
                             gpsData->getCoordenada().getLatitud(), gpsData->getCoordenada().getLongitud())
                             > this->metrosEntrePuntos;
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

            if (posicionValida(nuevo))
            {
                delete this->gpsData;
                this->gpsData = nuevo;
                return true;
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
