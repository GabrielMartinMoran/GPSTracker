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
        while (this->locked)
        {
            delay(100);
        }
        this->locked = true;
        //escribir en la sd
        this->locked = false;
    }else
    {
        while (this->locked)
        {
            delay(100);
        }
        this->locked = true;
        //enviar por wifi
        this->locked = false;
    }
    
}

void IOManager::write(std::string line)
{
    ioConcurrencia(true, line);
}

void IOManager::read()
{
}