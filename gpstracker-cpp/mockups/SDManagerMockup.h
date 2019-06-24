#ifndef SDManagerMockup_h
#define SDManagerMockup_h

#include <iostream>
#include <interfaces/ISDManager.h>

class SDManagerMockup : public ISDManager {
    
    public:
        std::vector<std::string>  *dataLines;
        std::string deletedFilePath;
        std::string writtenFile;

        bool isValidSD() {
            return true;
        }
        void listDir(const char * dirname, uint8_t levels) {}
        std::vector<std::string> getFiles(const char *dirname){
            //no implementado
            return *dataLines;
        }
        void createDir(const char * path) {}
        void removeDir(const char * path) {}
        std::string readLine(const char * path, unsigned int index) {
            return "";
        }
        std::vector<std::string> *readFileLines(const char * path) {
            return dataLines;
        }
        bool writeFile(const char * path, const std::string data) {
            writtenFile = data;
            return true;
        }
        bool appendFile(const char * path, const std::string data){
            return true;
        }
        bool renameFile(const char * path1, const char * path2){
            return true;
        }
        bool deleteFile(const char * path) override {
            deletedFilePath = std::string(path);
            return true;
        }
        virtual uint64_t getCardSize(){
            return 0;
        }
        bool fileExists(std::string filename){
            //no implementado
            return true;
        };
        size_t getFileSize(std::string filename){
            //no implementado
            return 0;
        }

        std::string readFile(std::string filename){
            //no implementado
            return std::string("no implementado");
        }
};

#endif