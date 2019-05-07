#ifndef ISDManager_h
#define ISDManager_h

#include <iostream>
#include <vector>

class ISDManager {

    public:
        virtual bool isValidSD() {return 0;}
        virtual void listDir(const char * dirname, uint8_t levels) {}
        virtual void createDir(const char * path) {}
        virtual void removeDir(const char * path) {}
        virtual void readFileAndPrintContent(const char * path) {}
        virtual std::string readLine(const char * path, unsigned int index) {return "";}
        virtual std::vector<std::string> *readFileLines(const char * path) {return nullptr;}
        virtual void writeFile(const char * path, const std::string data) {}
        virtual void appendFile(const char * path, const std::string data) {}
        virtual void renameFile(const char * path1, const char * path2) {}
        virtual void deleteFile(const char * path) {}
        virtual void testFileIO(const char * path) {}
        /**
         * Returns SD card size in MB
         */
        virtual uint64_t getCardSize() {return 0;}
};

#endif