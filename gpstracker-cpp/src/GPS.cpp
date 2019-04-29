#include "GPS.h"

void GPS::actualizar(){
    String datos = controladorGPSMockup->leerInformacion();
    latitud = 3751.65;
    longitud = 14507.36;
};

GPS::~GPS(){
    delete controladorGPSMockup;
}

