#ifndef IOManager_h
#define IOManager_h

#include <iostream>
#include <algorithm>
#include <mutex>
#include <Arduino.h>
#include <interfaces/ISDManager.h>
#include <platformDependent/WiFiConnector.h>

#define LINE_DATE_LENGTH 17 //Largo fijo desde el inicio de la cadena a escribir que corresponde a la date y hour del GPS
#define CURRENT_FILE_IDENTIFIER "C-" //Esta cadena se concatena al inicio del nombre del archivo en uso
#define FILESIZE_WITH_CONNECTION 200
#define FILESIZE_WITHOUT_CONNECTION 4000
#define FILE_ESTENSION ".data"

class IOManager
{
private:
    bool locked;
    ISDManager *sdManager;
    WiFiConnector *wifiConnector;
    std::mutex io_mutex;
    void ioConcurrencia(bool writing, std::string line);
    bool isLocked();
    void lock();
    void unlock();

public:
    IOManager(ISDManager *sdManager, WiFiConnector *wifiConnector);
    void write(std::string line);
    std::string read();
    std::string getFilenameToWrite(std::string line);
    bool hasMaxFileSize(std::string filename);
    std::string getFilenameToSend();
    void deleteFile(std::string filename);
    std::string getFileContent(std::string filename);
};

#endif