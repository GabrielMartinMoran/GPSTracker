#include <GPS/GPS.h>

GPS::GPS(IGPSController *GPSController, double metrosEntrePuntos) : GPSController(GPSController), metrosEntrePuntos(metrosEntrePuntos)
{
}

bool GPS::posicionValida(GPSData *gpsData)
{
    double distancia = distance_m(this->gpsData->getCoordenada().getLatitud(), this->gpsData->getCoordenada().getLongitud(),
                       gpsData->getCoordenada().getLatitud(), gpsData->getCoordenada().getLongitud());
    std::cout << "distancia en metros : " << distancia << std::endl;
    return distancia > this->metrosEntrePuntos;
}

bool GPS::actualizado()
{
    if (this->gpsDataBuffer != nullptr)
    {
        delete this->gpsData;
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
                if (this->posicionesInvariadas >= this->maxPosicionesInvariadas)
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
