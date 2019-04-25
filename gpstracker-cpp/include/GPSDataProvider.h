#include "SDManager.h"
#include <Arduino.h>

class GPSDataProvider {
    private:
        SDManager *sdManager;
        char* path;
    public:
        GPSDataProvider(char *dataPath);
        ~GPSDataProvider();
        void registerData(String time, String x_coord, String y_coord);
        String readData(unsigned int index);
};