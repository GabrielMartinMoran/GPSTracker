#include "GPS.h"

void GPS::actualizar(){
    int latitudAux;
    int longitudAux;
    boolean NAux;
    boolean WAux;
    String datos = controladorGPSMockup->leerInformacion();
    StringTokenizer tokens(datos, ",");
    if(tokens.nextToken() == "$PGRMC"){
        tokens.nextToken(); // Time of fix 22:54:46 UTC
        if(tokens.nextToken() == "A"){
            latitud = tokens.nextToken().toFloat();
            N = tokens.nextToken() == "N";
            longitud = tokens.nextToken().toFloat();
            W = tokens.nextToken() == "W";
            //tokens.nextToken(); Speed over ground, Knots
            //tokens.nextToken(); Course Made Good, True
            //tokens.nextToken(); Date of fix  19 November 1994
            //tokens.nextToken(); Magnetic variation 20.3 deg East
            //tokens.nextToken(); mandatory checksum
        }
    }
}

GPS::~GPS(){
    delete controladorGPSMockup;
}

