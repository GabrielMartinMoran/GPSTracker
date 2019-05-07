#ifndef SerialControllerMockup_h
#define SerialControllerMockup_h

#include <iostream>

class SerialController {
    public:
        static void println(std::string data){
            std::cout << data << std::endl;
        };
        static void println(int data){
            std::cout << data << std::endl;
        }
        static void print(std::string data){
            std::cout << data;
        }
        static void print(int data){
            std::cout << data;
        }
};

#endif