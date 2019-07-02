#ifndef DateTime_h
#define DateTime_h

#include <exceptions/InvalidDateException.ex>
#include <exceptions/InvalidTimeException.ex>

class DateTime
{
private:
    unsigned int hour = 0;
    unsigned int minute = 0;
    unsigned int second = 0;
    unsigned int day = 0;
    unsigned int month = 0;
    unsigned int year = 0;

public:
    DateTime(unsigned int day, unsigned int month, unsigned int year, unsigned int hour, unsigned int minute, unsigned int second);
    unsigned int getDay();
    unsigned int getMonth();
    unsigned int getYear();
    unsigned int getHour();
    unsigned int getMinute();
    unsigned int getSecond();
    ~DateTime();
};
#endif