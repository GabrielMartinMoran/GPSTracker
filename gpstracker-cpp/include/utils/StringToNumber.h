#ifndef StringToNumber_h
#define StringToNumber_h

#include <sstream>
#include <string>

template <typename T>
T stringToNumber(const std::string &numberAsString)
{
    T valor;

    if (numberAsString.length() == 0)
    {
        return 0;
    }
    std::stringstream stream(numberAsString);
    stream >> valor;
    if (stream.fail())
    {
        std::runtime_error e(numberAsString);
        throw e;
    }
    return valor;
}

#endif