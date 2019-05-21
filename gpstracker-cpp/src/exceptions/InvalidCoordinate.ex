#ifndef InvalidCoordinate_ex
#define InvalidCoordinate_ex

#include <exception>

class InvalidCoordinate : public std::exception
{
public:
    const char* what() const throw()
    {
        return "Error: coordenada invalida";
    }
};
#endif