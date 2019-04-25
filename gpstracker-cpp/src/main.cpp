#include <Arduino.h>
/*
void setup() {
  Serial.begin(115200);
  Serial.println("Iniciando dispositivo");

  String msg = "Hola, esta es una prueba de strings";
  Serial.println(msg);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(2000);
}
*/

/*
* Connect the SD card to the following pins:
*
* SD Card | ESP32
* D2 -
* D3 SS
* CMD MOSI
* VSS GND
* VDD 3.3V
* CLK SCK
* VSS GND
* D0 MISO
* D1 -
*/

//#include "SDManager.h"
//#include "Multithreading.h"
#include "GPSDataProvider.h"



void setup(){

    Serial.begin(115200);

    GPSDataProvider *dataProvider = new GPSDataProvider("/data.txt");

    dataProvider->registerData("24042019220600", "0.123", "3.243");
    Serial.println(dataProvider->readData(5));

    delete dataProvider;

    
    /*

    SDManager *sdManager = new SDManager();

    if(!sdManager->isValidSD()){
        return;
    }

    Serial.printf("SD Card Size: %lluMB\n", sdManager->getCardSize());

    sdManager->listDir("/", 0);
    sdManager->createDir("/mydir");
    sdManager->listDir("/", 0);
    sdManager->removeDir("/mydir");
    sdManager->listDir("/", 2);
    sdManager->writeFile("/hello.txt", "Hello ");
    sdManager->appendFile("/hello.txt", "World!\n");
    sdManager->readFile("/hello.txt");
    sdManager->deleteFile("/foo.txt");
    sdManager->renameFile("/hello.txt", "/foo.txt");
    sdManager->readFile("/foo.txt");
    sdManager->testFileIO("/test.txt");

    //Liberamos la memoria
    delete sdManager;
    */
    
    /*
    //MULTITHREADING
    Multithreading *mt = new Multithreading();

    mt->beginTest();

    delete mt;
    */

}
 
void loop(){
}

/*

#ifndef LED_BUILTIN
#define LED_BUILTIN 13
#endif

void setup()
{
  // initialize LED digital pin as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  // turn the LED on (HIGH is the voltage level)
  digitalWrite(LED_BUILTIN, HIGH);

  // wait for a second
  delay(1000);

  // turn the LED off by making the voltage LOW
  digitalWrite(LED_BUILTIN, LOW);

   // wait for a second
  delay(1000);
}
*/