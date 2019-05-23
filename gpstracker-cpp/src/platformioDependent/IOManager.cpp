#include <platformioDependent/IOManager.h>

IOManager *IOManager::getInstance()
{
    if (instance == NULL)
    {
        instance = new IOManager();
    }

    return instance;
}

IOManager *IOManager::instance = NULL;

IOManager::IOManager() {}