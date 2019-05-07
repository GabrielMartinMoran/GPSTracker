#ifndef SDManagerMockup_h
#define SDManagerMockup_h

#include <iostream>
#include <interfaces/ISDManager.h>

class SDManagerMockup : public ISDManager {
    
    public:
        std::vector<std::string>  *dataLines;
        SDManagerMockup(){}
        ~SDManagerMockup(){}
        bool isValidSD() override {
            return true;
        }
        std::string readLine(const char * path, unsigned int index) override {
            return "";
        }
        std::vector<std::string> *readFileLines(const char * path) override {
            return dataLines;
        }
        void writeFile(const char * path, const std::string data) override {

        }
        void deleteFile(const char * path) override {

        }
};

#endif