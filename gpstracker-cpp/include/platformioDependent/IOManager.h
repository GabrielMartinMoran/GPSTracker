#ifndef IOManager_h
#define IOManager_h

#include <iostream>
#include <algorithm>
#include <mutex>
#include <Arduino.h>
#include <platformioDependent/SDManager.h>
#include <platformioDependent/WiFiConnector.h>

#define LINE_DATE_LENGTH 17 //Largo fijo desde el inicio de la cadena a escribir que corresponde a la fecha y hora del GPS
#define CURRENT_FILE_IDENTIFIER "C-" //Esta cadena se concatena al inicio del nombre del archivo en uso
#define FILESIZE_WITH_CONNECTION 200
#define FILESIZE_WITHOUT_CONNECTION 4000
#define FILE_ESTENSION ".data"

class IOManager
{
private:
    bool locked;
    SDManager *sdManager;
    WiFiConnector *wifiConnector;
    std::mutex io_mutex;
    void ioConcurrencia(bool writing, std::string line);
    bool isLocked();
    void lock();
    void unlock();

public:
    IOManager(SDManager *sdManager, WiFiConnector *wifiConnector);
    void write(std::string line);
    std::string read();
    bool availableToSend();
    std::string getFilenameToWrite(std::string line);
    bool hasMaxFileSize(std::string filename);
    std::string getFilenameToSend();
    void deleteFile(std::string filename);
    std::string getFileContent(std::string filename);
};

#endif