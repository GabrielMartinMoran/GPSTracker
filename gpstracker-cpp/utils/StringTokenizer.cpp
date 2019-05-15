/*
  StringTokenizer.h - Library for spliting strings into tokens using delimiters.
  Created by Ujjwal Syal, February 22, 2016.
  Released into the public domain.
*/

#include "StringTokenizer.h"

StringTokenizer::StringTokenizer(std::string str, std::string del)
{
    _str = str;
    _del = del;
    ptr = 0;
}

bool StringTokenizer::hasNext()
{
    if (ptr < _str.length())
    {
        return true;
    }
    else
    {
        return false;
    }
}

std::string StringTokenizer::nextToken()
{
    if (ptr >= _str.length())
    {
        ptr = _str.length();
        return "";
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