#include <GPS/Coordinate.h>

Coordinate::Coordinate(double latitude, double longitude)
{
    if (latitude > 180 || latitude < -180 || longitude > 180 || longitude < -180)
    {
        throw InvalidCoordinateException();
    }
    this->latitude = latitude;
    this->longitude = longitude;
}

double Coordinate::getLatitude()
{
    return this->latitude;
}
double Coordinate::getLongitude()
{
    return this->longitude;
}

Coordinate::~Coordinate()
{
}