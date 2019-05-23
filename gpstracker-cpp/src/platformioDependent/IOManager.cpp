#include <platformioDependent/IOManager.h>

IOManager::IOManager() {}

IOManager volatile *IOManager::getInstance()
{
    static IOManager instance;
    return &instance;
}

bool volatile IOManager::locked()
{
    return this->lock;
}
