#include <utils/Haversine.h>
//calculate haversine distance for linear distance
double haversine_m(double *lat1, double *long1, double *lat2, double *long2)
{
    double d2r = 0.01745329251994329576923690768489;
    double a = pow(sin((*lat2 - *lat1) * d2r / 2.0), 2) + cos(*lat1 * d2r) * cos(*lat2 * d2r) * pow(sin((*long2 - *long1) * d2r / 2.0), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a)) * 6367 * 1000;

    return c;
}