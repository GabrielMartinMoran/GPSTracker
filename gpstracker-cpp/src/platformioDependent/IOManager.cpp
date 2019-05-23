#include <platformioDependent/IOManager.h>

IOManager volatile *IOManager::getInstance()
{
    static IOManager instance;
    return &instance;
}

IOManager::IOManager() {}