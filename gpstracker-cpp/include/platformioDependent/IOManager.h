#ifndef IOManager_h
#define IOManager_h

#include <iostream>

class IOManager
{
private:
    static IOManager *instance;
    bool locked;
    IOManager();

public:
    static IOManager *getInstance();
    bool isLocked();
    void lock(bool estate);
};

#endif