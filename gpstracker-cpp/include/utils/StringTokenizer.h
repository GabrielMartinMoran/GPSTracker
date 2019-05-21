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