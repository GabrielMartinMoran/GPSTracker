#ifndef Coordenada_h
#define Coordenada_h

#include <exceptions/InvalidCoordinateException.ex>

class Coordinate
{
private:
    double latitude = 0;
    double longitude = 0;

public:
    Coordinate(double latitude, double longitude);
    double getLatitude();
    double getLongitude();
    ~Coordinate();
};
#endif