#ifndef IOManager_h
#define IOManager_h

#include <iostream>
#include <mutex>
#include <Arduino.h>

class IOManager
{
private:
    bool locked;
    std::mutex io_mutex;
    void ioConcurrencia(bool writing, std::string line);
    bool isLocked();
    void lock();
    void unlock();
public:
    IOManager();
    void write(std::string line);
    void read();
};

#endif