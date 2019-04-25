#include "SDManager.h"

bool SDManager::isValidSD(){
    if(!SD.begin()) {
        Serial.println("SD Card Mount Failed");
        return false;
    }
    if(SD.cardType() == CARD_NONE) {
        Serial.println("No SD card attached");
        return false;
    }
    return true;
}

void SDManager::listDir(const char * dirname, uint8_t levels) {
    if(!isValidSD()){
        return;
    }
    Serial.printf("Listing directory: %s\n", dirname);

    File root = fs.open(dirname);
    if(!root) {
        Serial.println("Failed to open directory");
        return;
    }
    if(!root.isDirectory()) {
        Serial.println("Not a directory");
        return;
    }

    File file = root.openNextFile();
    while(file) {
        if(file.isDirectory()) {
            Serial.print(" DIR : ");
            Serial.println(file.name());
            if(levels) {
                listDir(file.name(), levels -1);
            }
        } else {
            Serial.print(" FILE: ");
            Serial.print(file.name());
            Serial.print(" SIZE: ");
            Serial.println(file.size());
        }
        file = root.openNextFile();
    }
}

void SDManager::createDir(const char * path) {
    if(!isValidSD()){
        return;
    }
    Serial.printf("Creating Dir: %s\n", path);
    if(fs.mkdir(path)) {
        Serial.println("Dir created");
    } else {
        Serial.println("mkdir failed");
    }
}

void SDManager::removeDir(const char * path) {
    if(!isValidSD()){
        return;
    }
    Serial.printf("Removing Dir: %s\n", path);
    if(fs.rmdir(path)) {
        Serial.println("Dir removed");
    } else {
        Serial.println("rmdir failed");
    }
}

void SDManager::readFile(const char * path) {
    if(!isValidSD()){
        return;
    }
    Serial.printf("Reading file: %s\n", path);

    File file = fs.open(path);
    if(!file) {
        Serial.println("Failed to open file for reading");
        return;
    }

    Serial.print("Read from file: ");
    while(file.available()) {
        Serial.write(file.read());
    }
}

String SDManager::readLine(const char * path, unsigned int index) {
    if(!isValidSD()){
        return "ERR";
    }
    File file = fs.open(path);
    if(!file) {
        Serial.println("Failed to open file for reading");
        return "ERR";
    }    
    unsigned int recNum = 1;
    while (file.available())
    {
        String list = file.readStringUntil('\r');
        if(recNum == index)
        {
            return list;
        }
        recNum++; // Count the record
    }
    return "EOF";
}

void SDManager::writeFile(const char * path, const char * message) {
    if(!isValidSD()){
        return;
    }
    Serial.printf("Writing file: %s\n", path);

    File file = fs.open(path, FILE_WRITE);
    if(!file) {
        Serial.println("Failed to open file for writing");
        return;
    }
    if(file.print(message)) {
        Serial.println("File written");
    } else {
        Serial.println("Write failed");
    }
}

void SDManager::appendFile(const char * path, const String message) {
    if(!isValidSD()){
        return;
    }
    Serial.printf("Appending to file: %s\n", path);

    File file = fs.open(path, FILE_APPEND);
    if(!file) {
        Serial.println("Failed to open file for appending");
        return;
    }
    if(file.print(message)) {
        Serial.println("Message appended");
    } else {
        Serial.println("Append failed");
    }
}

void SDManager::renameFile(const char * path1, const char * path2) {
    if(!isValidSD()){
        return;
    }
    Serial.printf("Renaming file %s to %s\n", path1, path2);
    if (fs.rename(path1, path2)) {
        Serial.println("File renamed");
    } else {
        Serial.println("Rename failed");
    }
}

void SDManager::deleteFile(const char * path) {
    if(!isValidSD()){
        return;
    }
    Serial.printf("Deleting file: %s\n", path);
    if(fs.remove(path)) {
        Serial.println("File deleted");
    } else {
        Serial.println("Delete failed");
    }
}

void SDManager::testFileIO(const char * path) {
    if(!isValidSD()){
        return;
    }
    File file = fs.open(path);
    static uint8_t buf[512];
    size_t len = 0;
    uint32_t start = millis();
    uint32_t end = start;
    if(file) {
        len = file.size();
        size_t flen = len;
        start = millis();
        while(len) {
            size_t toRead = len;
            if(toRead > 512) {
                toRead = 512;
            }
            file.read(buf, toRead);
            len -= toRead;
        }
        end = millis() - start;
        Serial.printf("%u bytes read for %u ms\n", flen, end);
        file.close();
    } else {
        Serial.println("Failed to open file for reading");
    }

    file = fs.open(path, FILE_WRITE);
    if(!file) {
        Serial.println("Failed to open file for writing");
        return;
    }

    size_t i;
    start = millis();
    for(i=0; i<2048; i++) {
        file.write(buf, 512);
    }
    end = millis() - start;
    Serial.printf("%u bytes written for %u ms\n", 2048 * 512, end);
    file.close();
}

uint64_t SDManager::getCardSize(){
    return SD.cardSize() / (1024 * 1024);
}