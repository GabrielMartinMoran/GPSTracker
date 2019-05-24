#include "utils/StringTokenizer.h"

StringTokenizer::StringTokenizer(std::string str, std::string del) : _str(str), _del(del), ptr(0)
{
}

bool StringTokenizer::hasNext()
{
    return ptr < _str.length();
}

std::string StringTokenizer::nextToken()
{
    if (ptr >= _str.length())
    {
        throw NoMoreTokensException();
    }

    std::string result = "";
    int delIndex = _str.find(_del, ptr);

    if (delIndex == std::string::npos)
    {
        result = _str.substr(ptr);
        ptr = _str.length();
        return result;
    }
    else
    {
        result = _str.substr(ptr, delIndex - ptr);
        ptr = delIndex + _del.length();
        return result;
    }
}