#ifndef EndConfigurationCallback_h
#define EndConfigurationCallback_h

#define MAX_TIME_UNTIL_DONE 1500 //In milliseconds

class EndConfigurationCallback
{
private:
    bool configurationEnded;
    bool deviceConnected;
    unsigned long int timeSinceLastRequest;
public:
    EndConfigurationCallback();
    ~EndConfigurationCallback();
    void resetTimeSinceLastRequest();
    void increaseTimer(unsigned int milliseconds);
    void setDeviceConnected();
    void endConfiguration();
    bool configurationDone();
};

#endif