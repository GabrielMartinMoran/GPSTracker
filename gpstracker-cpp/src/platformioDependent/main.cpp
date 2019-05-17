#include <thread>
#include <iostream>

#include <platformioDependent/Orchestator.h>
/*
#include <platformioDependent/SDManager.h>
#include <platformioDependent/SerialController.h>
#include <BluetoothServer.h>
#include <WiFiConfiguration.h>
#include <platformioDependent/Bluetooth.h>
#include <platformioDependent/WiFiConnector.h>
*/
void runWifiConnectionLoopThreaded(WiFiConnector *wifiConnector)
{
    wifiConnector->beginConnectionLoop();
}

void blinkLed()
{
    pinMode(LED_BUILTIN, OUTPUT);
    while (true)
    {
        digitalWrite(LED_BUILTIN, HIGH);
        delay(1000);
        digitalWrite(LED_BUILTIN, LOW);
        delay(1000);
    }
}

void setup()
{
    Orchestator *orchestator = new Orchestator();
    orchestator->start();
    /*
    SerialController *serialController = new SerialController();
    serialController->println("~~ Inicio del setup ~~");

    SDManager *sdManager = new SDManager();

    WiFiConfiguration *wifiConfiguration = new WiFiConfiguration(sdManager);

    //Este pedazo de codigo esta asi para realizar pruebas desde la APP de Android
    Serial.print("Redes WiFi Configuradas: ");
    Serial.println(wifiConfiguration->getConfiguredNetworks());
    if (wifiConfiguration->getConfiguredNetworks() == 0)
    {
        Serial.println("Configurando redes WiFi por defecto...");
        wifiConfiguration->addNetwork("ABC", "123");
        wifiConfiguration->addNetwork("DEF", "456");
        wifiConfiguration->addNetwork("GHI", "789");
        wifiConfiguration->addNetwork("Gabriel", "pass1234");
    }
    sdManager->isValidSD();

    Bluetooth *bluetooth = new Bluetooth();
    BluetoothServer *btServer = new BluetoothServer(wifiConfiguration, bluetooth, serialController);
    */
    //Para la SD habria que ver como hacer para administrar el envio, ya que podria ocurrir que hay que leer de un
    //archivo mientras el modulo que registra datos en el archivo trata de escribir.
    //Una posible solucion de esto es utilizar un Singleton que administre con delays o con 'critical zones'
    //(como con OpenMP) quien escribe y quien lee en cada momento.
    //Sea cual fuere la solucion es un tema a evaluar

    //Obtencion de datos del GPS
    //A continuación un código de ejemplo de como se debería instanciar este componente
    //GPSController *gpsController = new GPSController();
    //En un thread nuevo se deberia llamar a un loop que obtenga datos

    //Conexion WiFi
    //Es necesario evaluar problemas con el bluetooth si el wifi esta conectado
    //A continuación un código de ejemplo de como se debería instanciar este componente
    //WiFiConnector *wifiConnector = new WiFiConnector(wifiConfiguration);
    //En un thread nuevo se deberia llamar a una funcion que loopee y trate de conectarse en caso de que este desconectado
    /*
    WiFiConnector *wifiConnector = new WiFiConnector(wifiConfiguration);

    std::thread wifiConnectionLoopThread = std::thread(runWifiConnectionLoopThreaded, wifiConnector);

    std::thread ledBlinkThread = std::thread(blinkLed);
    
    wifiConnectionLoopThread.join();
    ledBlinkThread.join();
    
    */

    //Transmisor de datos a la aplicacion de android
    //este conectado a una red wifi
    //A continuación un código de ejemplo de como se debería instanciar este componente
    //DataTransmitter *dataTransmitter = new DataTransmitter(wifiConnector);
    //En un thread nuevo se deberia llamar a una funcion que envie datos si el wifiConnector pudo conectarse

    //delete bt;

    //btServer->start();
    /*
    pinMode(LED_BUILTIN, OUTPUT);
    bool estadoBTServer = true;
    btServer->start();
    digitalWrite(LED_BUILTIN, HIGH);
    delay(1000);
    uint16_t touchValue;
    while (true)
    {
        touchValue = touchRead(T4);
        //Serial.print("TOUCH VALUE: ");
        //Serial.println(touchValue);
        if (touchValue < 25)
        {
            estadoBTServer = !estadoBTServer;
            if (estadoBTServer)
            {
                Serial.println("Iniciando BLE Server");
                btServer->start();
                digitalWrite(LED_BUILTIN, HIGH);
            }
            else
            {
                Serial.println("Deteniendo BLE Server");
                btServer->stop();
                digitalWrite(LED_BUILTIN, LOW);
            }
            while (touchRead(T4) < 50)
            {
            }
        }
        delay(200);
    }*/
    
    //serialController->println("~~ Fin del setup ~~");

    //Deletes (ver donde ubicar) ya que aqui cuando termine el setup van a morir
    //¿Tiene sentido tener deletes para estas instancias que mueren solo si se reinicia el aparato?
    //Los componentes que se deberian eliminar de heap son con 'delete' son:
    /*
    delete sdManager;
    delete wifiConfiguration;   
    delete bluetooth;
    delete btServer;
    delete serialController;
    // SI SE IMPLEMENTA DE LA MANERA DESCRITA EN LOS COMENTARIOS:
    delete gpsController;
    delete wifiConnector;
    delete dataTransmitter;
    */

    //Tambien hay que tener en cuenta que hay que corregir las interfaces, poniendole a los metodos = 0
    //(aunque no sean void) en lugar de {} o {return #DATO_POR_DEFECTO#;}
    //Por ejemplo:
    //virtual void a() = 0;
    //virtual std::string b() = 0;
}

void loop()
{
}