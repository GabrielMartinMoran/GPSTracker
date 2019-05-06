#include "SDManager.h"
#include <Arduino.h>
#include <iostream>

class GPSDataProvider {
    private:
        SDManager *sdManager;
        char* path;
    public:
        GPSDataProvider(char *dataPath);
        ~GPSDataProvider();
        void registerData(String time, String x_coord, String y_coord);
        std::string readData(unsigned int index);
};