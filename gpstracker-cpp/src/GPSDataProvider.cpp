#include "GPSDataProvider.h"

GPSDataProvider::GPSDataProvider(char *dataPath)
{
    sdManager = new SDManager();
    path = dataPath;
}

GPSDataProvider::~GPSDataProvider()
{
    delete sdManager;
}

void GPSDataProvider::registerData(String time, String x_coord, String y_coord)
{
    String message = time + ";" + x_coord + ";" + y_coord + "\r";
    //char msgBuff[message.length() + 1];
    //message.toCharArray(msgBuff, message.length() + 1);
    //sdManager->appendFile(path, msgBuff);
    sdManager->appendFile(path, message);
}

String GPSDataProvider::readData(unsigned int index)
{
    return sdManager->readLine(path, index);
}