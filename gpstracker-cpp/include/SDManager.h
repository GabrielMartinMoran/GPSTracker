#ifndef SDManager_h
#define SDManager_h

#include "FS.h"
#include "SD.h"
//#include "SPI.h"
#include <Arduino.h>
#include <iostream>

class SDManager {
    
    private:
        fs::FS &fs = SD;
    public:
        SDManager();
        ~SDManager();
        bool isValidSD();
        void listDir(const char * dirname, uint8_t levels);
        void createDir(const char * path);
        void removeDir(const char * path);
        void readFileAndPrintContent(const char * path);
        String readLine(const char * path, unsigned int index);
        std::vector<String> *readFileLines(const char * path);
        void writeFile(const char * path, const String data);
        void appendFile(const char * path, const String data);
        void renameFile(const char * path1, const char * path2);
        void deleteFile(const char * path);
        void testFileIO(const char * path);
        /**
         * Returns SD card size in MB
         */
        uint64_t getCardSize();
};

#endif