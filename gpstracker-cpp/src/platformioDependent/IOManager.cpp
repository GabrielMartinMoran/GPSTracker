#include <platformioDependent/IOManager.h>

IOManager::IOManager()
{
    std::lock_guard<std::mutex> lock(this->io_mutex);
    this->locked = false;
}

void IOManager::write(std::string line){
    std::lock_guard<std::mutex> lock(this->io_mutex);
    while(this->locked){
        delay(100);
    }
    this->locked = true;
    //escribir en la sd
}