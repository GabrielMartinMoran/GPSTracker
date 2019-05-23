#ifndef IOManager_h
#define IOManager_h

#include <iostream>

class IOManager
{
private:
    static IOManager volatile *instance;
    bool volatile lock = false;
    IOManager();

public:
    static IOManager volatile *getInstance();
    bool volatile locked();
};

#endif