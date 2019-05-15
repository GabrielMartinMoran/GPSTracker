#include "platformioDependent/GPSDataProvider.h"
    //char msgBuff[message.length() + 1];
    //message.toCharArray(msgBuff, message.length() + 1); 
    //sdManager->appendFile(path, msgBuff);

GPSDataProvider::GPSDataProvider(char *dataPath){
    sdManager = new SDManager();
    path = dataPath;
}

GPSDataProvider::~GPSDataProvider(){
    //EVALUAR PORQUE HAY MEMORY LEAK PERO EXPLOTA
    //delete sdManager;
}

void GPSDataProvider::registerData(String time, String x_coord, String y_coord){
    String message = time + ";" + x_coord + ";" + y_coord + "\r";
    //char msgBuff[message.length() + 1];
    //message.toCharArray(msgBuff, message.length() + 1); 
    //sdManager->appendFile(path, msgBuff);
    sdManager->appendFile(path, std::string(message.c_str()));
}

std::string GPSDataProvider::readData(unsigned int index){
    return sdManager->readLine(path, index);
}