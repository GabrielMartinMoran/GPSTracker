#include "platformioDependent/GPSDataProvider.h"
    //char msgBuff[message.length() + 1];
    //message.toCharArray(msgBuff, message.length() + 1); 
    //sdManager->appendFile(path, msgBuff);

GPSDataProvider::GPSDataProvider(char *dataPath){
    sdManager = new SDManager(5);
    path = dataPath;
}

GPSDataProvider::~GPSDataProvider(){
    //EVALUAR PORQUE HAY MEMORY LEAK PERO EXPLOTA
    //delete sdManager;
}

void GPSDataProvider::registerData(std::string time, std::string x_coord, std::string y_coord){
    std::string message = std::string(time + ";" + x_coord + ";" + y_coord + "\r");
    //char msgBuff[message.length() + 1];
    //message.toCharArray(msgBuff, message.length() + 1); 
    //sdManager->appendFile(path, msgBuff);

    sdManager->appendFile(path, message);
}

std::string GPSDataProvider::readData(unsigned int index){
    return sdManager->readLine(path, index);
}