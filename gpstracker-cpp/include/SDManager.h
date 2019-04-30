#include "FS.h"
#include "SD.h"
//#include "SPI.h"
#include <Arduino.h>

class SDManager {
    
    private:
        fs::FS &fs = SD;
    public:
        bool isValidSD();
        void listDir(const char * dirname, uint8_t levels);
        void createDir(const char * path);
        void removeDir(const char * path);
        void readFile(const char * path);
        String readLine(const char * path, unsigned int index);
        void writeFile(const char * path, const char * message);
        void appendFile(const char * path, const String message);
        void renameFile(const char * path1, const char * path2);
        void deleteFile(const char * path);
        void testFileIO(const char * path);
        /**
         * Returns SD card size in MB
         */
        uint64_t getCardSize();
}; 