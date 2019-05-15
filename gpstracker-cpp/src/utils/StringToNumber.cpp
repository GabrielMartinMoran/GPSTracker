
#include <utils/StringToNumber.h>

template <typename T>
T StringToNumber(const std::string &numberAsString)
{
    T valor;

    std::stringstream stream(numberAsString);
    stream >> valor;
    if (stream.fail())
    {
        std::runtime_error e(numberAsString);
        throw e;
    }
    return valor;
}