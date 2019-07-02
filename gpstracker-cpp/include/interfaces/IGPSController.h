#ifndef IGPSController_h
#define IGPSController_h

#include <iostream>

class IGPSController
{
public:
    virtual ~IGPSController() {}
    virtual std::string getInformation() = 0;
    virtual bool isWaitingData() = 0;
};

#endif