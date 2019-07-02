#include <GPS/DateTime.h>

DateTime::DateTime(unsigned int day, unsigned int month, unsigned int year, unsigned int hour, unsigned int minute, unsigned int second)
{

    if (hour > 23 || minute > 59 || second > 59)
    {
        throw InvalidTimeException();
    }
    if (month < 1 || month > 12)
    {
        throw InvalidDateException();
    }
    unsigned int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (day < 1 || day > monthDays[month - 1])
    {
        throw InvalidDateException();
    }

    this->day = day;
    this->month = month;
    this->year = year;
    this->hour = hour;
    this->minute = minute;
    this->second = second;
}

unsigned int DateTime::getHour()
{
    return this->hour;
}

unsigned int DateTime::getMinute()
{
    return this->minute;
}

unsigned int DateTime::getSecond()
{
    return this->second;
}

unsigned int DateTime::getDay()
{
    return this->day;
}

unsigned int DateTime::getMonth()
{
    return this->month;
}

unsigned int DateTime::getYear()
{
    return this->year;
}

DateTime::~DateTime()
{
}