#include <utils/Haversine.h>
//calculate haversine distance for linear distance
double haversine_m(float latitud1, float longitud1, float latitud2, float longitud2)
{
    double lat1 = (double)latitud1;
    double long1 = (double)longitud1;
    double lat2 = (double)latitud2;
    double long2 = (double)longitud2;

    double d2r = 0.01745329251994329576923690768489;
    double dlong = (long2 - long1) * d2r;
    double dlat = (lat2 - lat1) * d2r;
    double a = pow(sin(dlat / 2.0), 2) + cos(lat1 * d2r) * cos(lat2 * d2r) * pow(sin(dlong / 2.0), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double d = 6367 * c * 1000;

    return d;
}