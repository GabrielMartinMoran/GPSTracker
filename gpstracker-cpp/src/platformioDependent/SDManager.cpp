#include "platformioDependent/SDManager.h"

bool SDManager::isValidSD()
{
    if (!SD.begin(21))
    {
        Serial.println("SD Card Mount Failed");
        return false;
    }
    if (SD.cardType() == CARD_NONE)
    {
        Serial.println("No SD card attached");
        return false;
    }
    //Serial.println("Detected SD is valid");
    return true;
}

void SDManager::listDir(const char *dirname, uint8_t levels)
{
    if (!isValidSD())
    {
        return;
    }
    Serial.printf("Listing directory: %s\n", dirname);

    File root = SD.open(dirname);
    if (!root)
    {
        Serial.println("Failed to open directory");
        return;
    }
    if (!root.isDirectory())
    {
        Serial.println("Not a directory");
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
        file = root.openNextFile();
    }
}

void SDManager::createDir(const char *path)
{
    if (!isValidSD())
    {
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
}

void SDManager::removeDir(const char *path)
{
    if (!isValidSD())
    {
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
}

std::vector<std::string> *SDManager::readFileLines(const char *path)
{
    std::vector<std::string> *list = new std::vector<std::string>();
    if (!isValidSD()) return list;
    File file = SD.open(path);
    if (!file) return list;
    while (file.available())
    {
        std::string data = file.readStringUntil('\n').c_str();
        list->push_back(data);
    }
    file.close();
    return list;
}

std::string SDManager::readLine(const char *path, unsigned int index)
{
    if (!isValidSD()) return "ERR";
    File file = SD.open(path);
    if (!file) return "ERR";
    size_t recNum = 1;
    while (file.available())
    {
        std::string list = file.readStringUntil('\n').c_str();
        if (recNum == index)
        {
            file.close();
            return list;
        }
        recNum++;
    }
    file.close();
    return "EOF";
}

bool SDManager::writeFile(const char *path, const std::string data)
{
    if (!isValidSD()) return false;
    File file = SD.open(path, FILE_WRITE);
    bool result = file && file.print(data.c_str());
    file.close();
    return result;
}

bool SDManager::appendFile(const char *path, const std::string data)
{
    if (!isValidSD()) return false;
    File file = SD.open(path, FILE_APPEND);
    bool result = file && file.print(data.c_str());
    file.close();
    return result;
}

bool SDManager::renameFile(const char *path1, const char *path2)
{
    if (!isValidSD()) return false;
    return SD.rename(path1, path2);
}

bool SDManager::deleteFile(const char *path)
{
    if (!isValidSD()) return false;
    return SD.remove(path);
}

uint64_t SDManager::getCardSize()
{
    return SD.cardSize() / (1024 * 1024);
}