#ifndef IGPSController_h
#define IGPSController_h

#include <iostream>

class IGPSController
{
  public:
    virtual ~IGPSController() {}
    virtual std::string getInformation() = 0;
    virtual bool isDataWaiting() = 0;
};

#endif