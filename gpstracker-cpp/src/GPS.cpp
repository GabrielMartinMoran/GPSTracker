#include <GPS.h>

GPS::GPS(IGPSController *GPSController)
{
    this->GPSController = GPSController;
}

bool GPS::posicionValida(GPSData gpsData)
{
    return haversine_m(this->gpsData.getLatitud(), this->gpsData.getLongitud(), gpsData.getLatitud(), gpsData.getLongitud()) > 2.5;
}

bool GPS::actualizado()
{
    while (this->GPSController->isDataWaiting())
    {
        std::string datos = this->GPSController->getInformation();
        GPSData nuevo = GPSData(datos);
        if (nuevo.isValido())
        {
            if (posicionValida(nuevo))
            {
                this->gpsData = nuevo;
                return true;
            }
        }
    }
    return false;
}

GPSData GPS::getGPSData(){
    return this->gpsData;
}

GPS::~GPS()
{
}
