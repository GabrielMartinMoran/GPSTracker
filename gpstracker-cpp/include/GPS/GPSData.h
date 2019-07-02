#ifndef GPSData_h
#define GPSData_h

#include <string>
#include <stdio.h>
#include <cmath>
#include <utils/StringTokenizer.h>
#include <utils/StringToNumber.h>
#include <GPS/DateTime.h>
#include <GPS/Coordinate.h>
#include <exceptions/InvalidReadGPSDataException.ex>

class GPSData
{
private:
    DateTime *dateTime = nullptr;
    Coordinate *coordinate = nullptr;
    void parseTime(std::string time, unsigned int *hourDay, unsigned int *minuteMonth, unsigned int *secondYear);
    double parseCoordinate(std::string coordinate);
    std::string rawData;
    bool isMotionless();
    bool _motionless = false;
    void invalidate();
    std::string calculateChecksum(std::string sentences);

public:
    GPSData(std::string data);
    DateTime getDateTime();
    Coordinate getCoordinate();
    bool isValid();
    void motionless();
    std::string getRawData();
    std::string getNormalizedData();
    ~GPSData();
};
#endif