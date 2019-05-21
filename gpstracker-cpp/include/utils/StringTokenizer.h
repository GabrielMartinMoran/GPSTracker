/*
  StringTokenizer.h - Library for spliting strings into tokens using delimiters.
  Created by Ujjwal Syal, February 22, 2016.
  Released into the public domain.
*/
#ifndef StringTokenizer_h
#define StringTokenizer_h
#include <iostream>
#include <exceptions/NoMoreTokensException.ex>

class StringTokenizer
{
  public:
    StringTokenizer(std::string str, std::string del);
    bool hasNext();
    std::string nextToken();

  private:
    std::string _str;
    std::string _del;
    int ptr;
};

#endif