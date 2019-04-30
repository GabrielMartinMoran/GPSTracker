#ifndef Multithreading_h
#define Multithreading_h
//#include "pthread.h"
#include <Arduino.h>
#include <thread>
#include <iostream>

class Multithreading
{
public:
    static void printThread(int number);
    void beginTest();
};

#endif