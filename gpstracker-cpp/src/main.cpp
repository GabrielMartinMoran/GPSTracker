#include <SDManager.h>
#include <SerialController.h>
#include <BluetoothServer.h>
#include <WiFiConfiguration.h>
#include <Bluetooth.h>

void setup()
{
    //Habria que ver si combiene utilizar el SerialController como clase estatica (como esta ahora) o instanciarla
    //y asi poder utilizar un mockup para los tests (esta opcion es la que parece mas correcta)
    //En ese caso habria que hacer:
    //SerialController *serialController = new SerialController();
    //y luego pasar el puntero a todas las clases que lo utilicen
    SerialController::println("~~ Inicio del setup ~~");
    
    SDManager *sdManager = new SDManager();
    
    WiFiConfiguration *wifiConfiguration = new WiFiConfiguration(sdManager);
    
    //Este pedazo de codigo esta asi para realizar pruebas desde la APP de Android
    if (wifiConfiguration->getConfiguredNetworks() == 0)
    {
        wifiConfiguration->addNetwork("ABC", "123");
        wifiConfiguration->addNetwork("DEF", "456");
        wifiConfiguration->addNetwork("GHI", "789");
    }

    Bluetooth *bluetooth = new Bluetooth();
    BluetoothServer *btServer = new BluetoothServer(wifiConfiguration, bluetooth);

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

    //Transmisor de datos a la aplicacion de android
    //este conectado a una red wifi
    //A continuación un código de ejemplo de como se debería instanciar este componente
    //DataTransmitter *dataTransmitter = new DataTransmitter(wifiConnector);
    //En un thread nuevo se deberia llamar a una funcion que envie datos si el wifiConnector pudo conectarse

    //delete bt;
    SerialController::println("~~ Fin del setup ~~");

    //Deletes (ver donde ubicar) ya que aqui cuando termine el setup van a morir
    //¿Tiene sentido tener deletes para estas instancias que mueren solo si se reinicia el aparato?
    //Los componentes que se deberian eliminar de heap son con 'delete' son:
    /*
    delete sdManager;
    delete wifiConfiguration;   
    delete bluetooth;
    delete btServer;
    // SI SE IMPLEMENTA DE LA MANERA DESCRITA EN LOS COMENTARIOS:
    delete gpsController;
    delete wifiConnector;
    delete dataTransmitter;
    // SI SE UTILIZARA EL SerialController DE MANERA NO ESTATICA:
    delete serialController;
    */
}

void loop()
{
}