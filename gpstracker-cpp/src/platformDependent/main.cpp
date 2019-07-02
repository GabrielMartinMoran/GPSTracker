#include <iostream>
#include <platformDependent/Orchestator.h>

void setup()
{
    try
    {
        Orchestator *orchestator = new Orchestator();
        orchestator->start();
    }
    catch (std::exception &e)
    {
        Serial.println(e.what());
    }
}

void loop()
{
}