#ifndef InvalidDate_ex
#define InvalidDate_ex

#include <exception>

class InvalidDateException : public std::exception
{
public:
    const char* what() const throw()
    {
        return "Error: Fecha Invalida";
    }
};
#endif