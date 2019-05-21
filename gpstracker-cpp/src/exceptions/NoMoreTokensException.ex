#include <exception>

class NoMoreTokensException : public std::exception
{
public:
    const char* what() const throw()
    {
        return "Error: no hay mas tokens";
    }
};