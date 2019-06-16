#ifndef InvalidTime_ex
#define InvalidTime_ex

#include <exception>

class InvalidTimeException : public std::exception
{
public:
    const char *what() const throw()
    {
        return "InvalidTimeException: Hora Invalida";
    }
};
#endif