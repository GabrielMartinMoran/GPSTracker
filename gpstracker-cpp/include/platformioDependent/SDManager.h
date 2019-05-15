#ifndef SDManager_h
#define SDManager_h

#include <interfaces/ISDManager.h>
#include <iostream>
#include "FS.h"
#include "SD.h"
//#include "SPI.h"
#include <Arduino.h>

class SDManager : public ISDManager {

    public:
        bool isValidSD();
        void listDir(const char * dirname, uint8_t levels);
        void createDir(const char * path);
        void removeDir(const char * path);
        std::string readLine(const char * path, unsigned int index);
        std::vector<std::string> *readFileLines(const char * path);
        bool writeFile(const char * path, const std::string data);
        bool appendFile(const char * path, const std::string data);
        bool renameFile(const char * path1, const char * path2);
        bool deleteFile(const char * path);
        /**
         * Returns SD card size in MB
         */
        uint64_t getCardSize();
};

#endif