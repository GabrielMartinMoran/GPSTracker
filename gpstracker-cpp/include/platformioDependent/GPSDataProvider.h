#include "platformioDependent/SDManager.h"
#include <Arduino.h>
#include <iostream>

class GPSDataProvider
{
private:
    SDManager *sdManager;
    char *path;

public:
    GPSDataProvider(char *dataPath);
    ~GPSDataProvider();
    void registerData(std::string time, std::string x_coord, std::string y_coord);
    std::string readData(unsigned int index);
};