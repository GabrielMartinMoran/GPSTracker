#include "platformioDependent/Multithreading.h"

void Multithreading::printThread(int number) {
    while(true){
        char buff[40];
        sprintf(buff, "Imprimiendo desde el thread %d", number);
        Serial.println(buff);
        delay(1000);
    }    
}

void Multithreading::beginTest(){
    int num_threads = 4;
    std::thread t[num_threads];
    for( int i = 0; i< num_threads; i++ ) {
        t[i] = std::thread(printThread, i + 1);
    }
    while(true){
        Serial.println("Imprimiendo desde el hilo principal");
        delay(1000);
    }
    for( int i = 0; i< num_threads; i++ ) {
        t[i].join();
    }
}