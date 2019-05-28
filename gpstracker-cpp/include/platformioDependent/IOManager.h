#ifndef IOManager_h
#define IOManager_h

#include <iostream>
#include <mutex>
#include <Arduino.h>
#include <platformioDependent/SDManager.h>

class IOManager
{
private:
    bool locked;
    SDManager *sdManager;
    std::mutex io_mutex;
    void ioConcurrencia(bool writing, std::string *line);
    bool isLocked();
    void lock();
    void unlock();

public:
    IOManager(SDManager *sdManager);
    void write(std::string *line);
    void read();
};

#endif