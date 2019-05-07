#ifndef SDManagerMockup_h
#define SDManagerMockup_h

#include <iostream>
#include <interfaces/SDManager.h>

class SDManagerMockup : public ISDManager {
    
    public:
        std::vector<std::string>  *dataLines;
        bool isValidSD(){
            return true;
        }
        std::string readLine(const char * path, unsigned int index);
        std::vector<std::string> *readFileLines(const char * path){
            return dataLines;
        }
        void writeFile(const char * path, const std::string data){

        }
        void deleteFile(const char * path){

        }
};

#endif