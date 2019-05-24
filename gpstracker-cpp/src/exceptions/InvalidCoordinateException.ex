#ifndef InvalidCoordinate_ex
#define InvalidCoordinate_ex

#include <exception>

class InvalidCoordinateException : public std::exception
{
public:
    const char* what() const throw()
    {
        return "Error: Coordenada Invalida";
    }
};
#endif