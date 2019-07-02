#include <GPS/GPS.h>

GPS::GPS(IGPSController *GPSController, double metersBetweenPoints) : GPSController(GPSController), metersBetweenPoints(metersBetweenPoints)
{
}

bool GPS::validPosition(GPSData *gpsData)
{
    double distance = distance_m(this->gpsData->getCoordinate().getLatitude(), this->gpsData->getCoordinate().getLongitude(),
                       gpsData->getCoordinate().getLatitude(), gpsData->getCoordinate().getLongitude());
    //std::cout << "distancia en metros : " << distancia << std::endl;
    return distance > this->metersBetweenPoints;
}

bool GPS::updated()
{
    if (this->gpsDataBuffer != nullptr)
    {
        delete this->gpsData;
        this->gpsData = this->gpsDataBuffer;
        this->gpsDataBuffer = nullptr;
        return true;
    }

    while (this->GPSController->isWaitingData())
    {
        GPSData *newData = new GPSData(this->GPSController->getInformation());

        if (newData->isValid())
        {
            if (this->gpsData == nullptr)
            {
                this->staticPositions = 0;
                this->gpsData = newData;
                return true;
            }

            if (validPosition(newData))
            {
                if (this->staticPositions >= this->maxStaticPositions)
                {
                    this->gpsDataBuffer = newData;
                }
                else
                {
                    delete this->gpsData;
                    this->gpsData = newData;
                }
                this->staticPositions = 0;
                return true;
            }

            if (this->staticPositions < this->maxStaticPositions)
            {
                this->staticPositions++;
            }
            else
            {
                this->gpsData->motionless();
            }
        }

        delete newData;
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
