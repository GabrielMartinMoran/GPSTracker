#include <EndConfigurationCallback.h>

EndConfigurationCallback::EndConfigurationCallback()
{
    this->configurationEnded = false;
    this->deviceConnected = false;
    this->timeSinceLastRequest = 0;
}

EndConfigurationCallback::~EndConfigurationCallback()
{
}

void EndConfigurationCallback::resetTimeSinceLastRequest()
{
    this->timeSinceLastRequest = 0;
}

void EndConfigurationCallback::setDeviceConnected()
{
    this->deviceConnected = true;
}

void EndConfigurationCallback::increaseTimer(unsigned int milliseconds)
{
    this->timeSinceLastRequest += milliseconds;
}

void EndConfigurationCallback::endConfiguration()
{
    this->configurationEnded = true;
}

bool EndConfigurationCallback::configurationDone()
{
    return this->configurationEnded || (!this->deviceConnected && this->timeSinceLastRequest >= MAX_TIME_UNTIL_DONE);
}
