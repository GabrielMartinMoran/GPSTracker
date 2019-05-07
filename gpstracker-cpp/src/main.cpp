#include <SDManager.h>
#include <SerialController.h>
#include <BluetoothServer.h>
#include <WiFiConfiguration.h>

void setup()
{
    //La inicializacion deberia estar en el SerialController
    SerialController::println("~~ Inicio del setup ~~");

    //Habria que inicializar ciertos componentes aqui para procurar la inversion
    //de dependencias para facilitar el testeo:
    
    SDManager *sdManager = new SDManager();

    //Inversion para WiFiConfiguration:
    //  - SDManager
    //  - StringTokenizer (habria que ver si es necesario ya que no toca ninguna libreria de arduino)
    
    WiFiConfiguration *wifiConfiguration = new WiFiConfiguration(sdManager);
    if (wifiConfiguration->getConfiguredNetworks() == 0)
    {
        wifiConfiguration->addNetwork("ABC", "123");
        wifiConfiguration->addNetwork("DEF", "456");
        wifiConfiguration->addNetwork("GHI", "789");
    }

    //Inversion para BluetoothServer:
    //  - WiFiConfiguration (Ya esta hecho)
    //  - StringTokenizer (habria que ver si es necesario ya que no toca ninguna libreria de arduino)
    //  - SerialController
    //  - Bluetooth

    BluetoothServer *btServer = new BluetoothServer(wifiConfiguration);

    //delete bt;
    SerialController::println("~~ Fin del setup ~~");

    //Deletes (ver donde ubicar)
    /*
    delete sdManager;
    */
}

void loop()
{
}