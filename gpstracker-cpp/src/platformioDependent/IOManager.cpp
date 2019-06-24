#include <platformioDependent/IOManager.h>

IOManager::IOManager(ISDManager *sdManager, WiFiConnector *wifiConnector)
{
    this->sdManager = sdManager;
    this->wifiConnector = wifiConnector;
    this->locked = false;
}

void IOManager::ioConcurrencia(bool writing, std::string line)
{
    std::lock_guard<std::mutex> lock(this->io_mutex);
    if (writing)
    {
        while (this->isLocked())
        {
            delay(100);
        }
        this->lock();
        //this->sdManager->appendFile("/test.txt", line);
        std::string filename = this->getFilenameToWrite(line);

        //Serial.print("Archivo a escribir: ");
        //Serial.println(filename.c_str());
        
        this->sdManager->appendFile(filename.c_str(), line);
        //Consultar el file size y cambiar de nombre el archivo
        //Serial.println("escribiendo SD");
        if(this->hasMaxFileSize(filename)){
            std::string newFilename = filename.c_str();
            newFilename.erase(1, sizeof(CURRENT_FILE_IDENTIFIER));
            this->sdManager->renameFile(filename.c_str(), newFilename.c_str());
            //Serial.print("Cambio de nombre en el archivo: ");
            //Serial.println(filename.c_str());
        }
        this->unlock();
    }
    else
    {
        while (this->isLocked())
        {
            delay(100);
        }
        this->lock();
        //enviar por wifi
        this->unlock();
    }
}

void IOManager::write(std::string line)
{
    ioConcurrencia(true, line);
}

std::string IOManager::read()
{
    std::string lines;
    return lines;
}

bool IOManager::isLocked()
{
    return this->locked;
}
void IOManager::lock()
{
    this->locked = true;
}
void IOManager::unlock()
{
    this->locked = false;
}
bool IOManager::availableToSend()
{
    return this->sdManager->fileExists("/test.txt");
}

std::string IOManager::getFilenameToWrite(std::string line)
{
    std::vector<std::string> files = sdManager->getFiles("/");
    for (size_t i = 0; i < files.size(); i++)
    {
        if(files.at(i).find(CURRENT_FILE_IDENTIFIER) != std::string::npos){
            return "/" + files.at(i);
        }
    }
    std::string filename =  line.substr(0, LINE_DATE_LENGTH);
    filename.erase(std::remove(filename.begin(), filename.end(), ' '), filename.end());
    filename.erase(std::remove(filename.begin(), filename.end(), '-'), filename.end());
    filename.erase(std::remove(filename.begin(), filename.end(), ':'), filename.end());
    filename.insert(0, CURRENT_FILE_IDENTIFIER);
    filename.insert(0, "/");
    filename.append(FILE_ESTENSION);
    Serial.print("Nuevo archivo de almacenamiento de datos generado: ");
    Serial.println(filename.c_str());
    return filename;
}

bool IOManager::hasMaxFileSize(std::string filename)
{
    size_t maxFileSize = FILESIZE_WITHOUT_CONNECTION;
    if(this->wifiConnector->isConnected()){
        maxFileSize = FILESIZE_WITH_CONNECTION;
    }
    size_t fileSize = sdManager->getFileSize(filename);
    return fileSize >= maxFileSize;
}

std::string IOManager::getFilenameToSend()
{
    std::vector<std::string> files = sdManager->getFiles("/");
    for (size_t i = 0; i < files.size(); i++)
    {
        if(files.at(i).find(CURRENT_FILE_IDENTIFIER) == std::string::npos &&
            files.at(i).find(FILE_ESTENSION) != std::string::npos){
            return "/" + files.at(i);
        }
    }
    return "";
}

void IOManager::deleteFile(std::string filename)
{
    sdManager->deleteFile(filename.c_str());
}

std::string IOManager::getFileContent(std::string filename)
{
    return sdManager->readFile(filename);
}