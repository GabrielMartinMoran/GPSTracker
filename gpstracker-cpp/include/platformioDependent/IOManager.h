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
public:
    IOManager();
    void write(std::string line);
    void read();
};

#endif