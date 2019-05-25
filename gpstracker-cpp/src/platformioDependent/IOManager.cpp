#include <platformioDependent/IOManager.h>

IOManager::IOManager()
{
    std::lock_guard<std::mutex> lock(this->io_mutex);
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
        //escribir en la sd
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