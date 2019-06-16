#include "platformioDependent/SDManager.h"

SDManager::SDManager(uint8_t ssPin) : ssPin(ssPin)
{
}

bool SDManager::isValidSD()
{
    if (!SD.begin(this->ssPin))
    {
        Serial.println("SD Card Mount Failed");
        return false;
    }
    if (SD.cardType() == CARD_NONE)
    {
        Serial.println("No SD card attached");
        return false;
    }
    return true;
}

std::vector<std::string> SDManager::getFiles(const char *dirname)
{
    std::vector<std::string> files = std::vector<std::string>();
    if (!isValidSD())
    {
        SD.end();
        return files;
    }
    File root = SD.open(dirname);
    if (!root || !root.isDirectory())
    {
        SD.end();
        return files;
    }
    File file = root.openNextFile();
    while (file)
    {
        if (!file.isDirectory())
        {
            files.push_back(file.name());
        }
        file.close();
        file = root.openNextFile();
    }
    root.close();
    file.close();
    SD.end();
    return files;
}

void SDManager::listDir(const char *dirname, uint8_t levels)
{
    if (!isValidSD())
    {
        SD.end();
        return;
    }
    Serial.printf("Listing directory: %s\n", dirname);

    File root = SD.open(dirname);

    if (!root)
    {
        Serial.println("Failed to open directory");
        SD.end();
        return;
    }
    if (!root.isDirectory())
    {
        root.close();
        Serial.println("Not a directory");
        SD.end();
        return;
    }

    File file = root.openNextFile();
    while (file)
    {
        if (file.isDirectory())
        {
            Serial.print(" DIR : ");
            Serial.println(file.name());
            if (levels)
            {
                listDir(file.name(), levels - 1);
            }
        }
        else
        {
            Serial.print(" FILE: ");
            Serial.print(file.name());
            Serial.print(" SIZE: ");
            Serial.println(file.size());
        }
        file.close();
        file = root.openNextFile();
    }
    root.close();
    SD.end();
    return;
}

void SDManager::createDir(const char *path)
{
    if (!isValidSD())
    {
        SD.end();
        return;
    }
    Serial.printf("Creating Dir: %s\n", path);
    if (SD.mkdir(path))
    {
        Serial.println("Dir created");
    }
    else
    {
        Serial.println("mkdir failed");
    }
    SD.end();
    return;
}

void SDManager::removeDir(const char *path)
{
    if (!isValidSD())
    {
        SD.end();
        return;
    }
    Serial.printf("Removing Dir: %s\n", path);
    if (SD.rmdir(path))
    {
        Serial.println("Dir removed");
    }
    else
    {
        Serial.println("rmdir failed");
    }
    SD.end();
    return;
}

std::vector<std::string> *SDManager::readFileLines(const char *path)
{
    std::vector<std::string> *list = new std::vector<std::string>();
    if (!isValidSD())
    {
        SD.end();
        return list;
    }
    File file = SD.open(path);
    if (!file)
    {
        SD.end();
        return list;
    }
    while (file.available())
    {
        std::string data = file.readStringUntil('\n').c_str();
        list->push_back(data);
    }
    file.close();
    SD.end();
    return list;
}

std::string SDManager::readLine(const char *path, unsigned int index)
{
    if (!isValidSD())
    {
        SD.end();
        return "ERR";
    }
    File file = SD.open(path);
    if (!file)
    {
        SD.end();
        return "ERR";
    }
    size_t recNum = 1;
    while (file.available())
    {
        std::string list = file.readStringUntil('\n').c_str();
        if (recNum == index)
        {
            file.close();
            SD.end();
            return list;
        }
        recNum++;
    }
    file.close();
    SD.end();
    return "EOF";
}

bool SDManager::writeFile(const char *path, const std::string data)
{
    if (!isValidSD())
    {
        SD.end();
        return false;
    }
    File file = SD.open(path, FILE_WRITE);
    bool result = file && file.print(data.c_str());
    file.close();
    SD.end();
    return result;
}

bool SDManager::appendFile(const char *path, const std::string data)
{
    if (!isValidSD())
    {
        SD.end();
        return false;
    }
    File file = SD.open(path, FILE_APPEND);
    bool result = file && file.print(data.c_str());
    file.close();
    SD.end();
    return result;
}

bool SDManager::renameFile(const char *path1, const char *path2)
{
    if (!isValidSD())
    {
        SD.end();
        return false;
    }
    bool result = SD.rename(path1, path2);
    SD.end();
    return result;
}

bool SDManager::deleteFile(const char *path)
{
    if (!isValidSD())
    {
        SD.end();
        return false;
    }
    SD.end();
    return SD.remove(path);
}

uint64_t SDManager::getCardSize()
{
    if (!isValidSD())
    {
        SD.end();
        return false;
    }
    uint64_t result = SD.cardSize() / (1024 * 1024);
    SD.end();
    return result;
}

bool SDManager::fileExists(std::string filename)
{
    if (!isValidSD())
    {
        SD.end();
        return false;
    }
    File file = SD.open(filename.c_str());
    bool exists = file && !file.isDirectory();
    file.close();
    SD.end();
    return exists;
}