#ifndef IOManager_h
#define IOManager_h

#include <iostream>

class IOManager
{
private:
    static IOManager volatile *instance;
    IOManager();

public:
    static IOManager volatile *getInstance();
};

#endif