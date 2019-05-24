#include <platformioDependent/IOManager.h>

IOManager::IOManager()
{
    this->locked = false;
}

IOManager *IOManager::getInstance()
{
    if (instance == 0)
    {
        instance = new IOManager();
    }
    return instance;
}

IOManager *IOManager::instance = 0;

bool IOManager::isLocked()
{
    return this->locked;
}

void IOManager::lock(bool estate)
{
    this->locked = estate;
}