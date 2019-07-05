# GPS Tracker

En este proyecto se plantea una solución para la implementación de un sistema de registro de geolocalización, para seguimiento de vehículos de modo incógnito. El mismo debe funcionar en un ESP32, registrando la geolocalización del dispositivo en una tarjeta Micro SD. Además, en caso de detectar que una red WiFi configurada esté disponible, debe transmitir los datos registrados. La configuración de las redes WiFi conocidas debe ser mediante Bluetooth (BLE) utilizando una aplicación Android.

Para la visualización de los datos registrados por el ESP32 se utiliza un mapa donde se marcan las posiciones registradas. Este mapa debe estar disponible tanto desde la aplicación Android como desde la web.

Dado que en MicroPython (lenguaje de programación Python para microcontroladores), la librería que se encarga de controlar el módulo bluetooth integrado no se encuentra funcional al momento de la realización de este trabajo, y que la configuración bluetooth es un requerimiento; la aplicación que corre en el ESP32 (GPS Tracker) se desarrolla con C++ utilizando el framework de Arduino. Para la compilación, despliegue y ejecución de pruebas automatizadas de la aplicación GPS Tracker, utilizando el IDE (Entorno de Desarrollo Integrado) PlatformIO, el cual funciona sobre Visual Studio Code.

En lo que respecta al registro de datos del GPS Tracker, el ESP32 envía peticiones HTTP tipo POST a una Web API REST, alojada en Heroku. Esta Web API procesa los datos recibidos por el ESP32 y los almacena en una base de datos Mongo DB. La Web API también se encarga de devolver los datos registrados hasta el momento en la base de datos y de brindar acceso al mapa online donde se pueden visualizar las posiciones registradas hasta el momento por los distintos dispositivos en un mapa online.

La aplicación de Android, la cual se encarga de la configuración del GPS Tracker mediante bluetooth y de la visualización del mapa de ubicaciones registradas; se encuentra programada en Java nativo para Android utilizando el IDE Android Studio.
