#ifndef InvalidReadGPSData_ex
#define InvalidReadGPSData_ex

#include <exception>

class InvalidReadGPSDataException : public std::exception
{
public:
    const char* what() const throw()
    {
        return "InvalidReadGPSDataException: No pueden leerse datos de GPSData cuando este es invalido";
    }
};
#endif