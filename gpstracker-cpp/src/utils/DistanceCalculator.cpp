#include <utils/DistanceCalculator.h>
//calculate haversine distance for linear distance
double distance_m(double lat1, double long1, double lat2, double long2)
{
    return sqrt(pow(lat2 - lat1, 2) + pow(long2 - long1, 2)) * 111319.44444444;
}