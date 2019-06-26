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
    if (this->gpsDataBuffer != nullptr)
    {
        this->gpsData = this->gpsDataBuffer;
        this->gpsDataBuffer = nullptr;
        return true;
    }

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
                if (this->gpsData->isInmovil())
                {
                    this->gpsDataBuffer = nuevo;
                }
                else
                {
                    delete this->gpsData;
                    this->gpsData = nuevo;
                }
                this->posicionesInvariadas = 0;
                return true;
            }

            if (this->posicionesInvariadas < this->maxPosicionesInvariadas)
            {
                this->posicionesInvariadas++;
                std::cout << this->posicionesInvariadas << std::endl;
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
