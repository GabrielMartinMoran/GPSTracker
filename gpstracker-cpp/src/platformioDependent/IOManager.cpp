#include <platformioDependent/IOManager.h>

IOManager::IOManager(SDManager *sdManager)
{
    this->sdManager = sdManager;
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
        this->sdManager->appendFile("/test.txt", line);
        Serial.println("escribiendo SD");
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

void IOManager::read()
{
}

bool IOManager::isLocked()
{
    return this->locked;
}
void IOManager::lock(){
    this->locked = true;
}
void IOManager::unlock(){
    this->locked = false;
}