#ifndef IOManager_h
#define IOManager_h

#include <iostream>

class IOManager
{
private:
    static IOManager *instance;
    IOManager();

public:
    static IOManager *getInstance();
};

#endif