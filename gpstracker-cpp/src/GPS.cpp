#include <GPS.h>
#include <Utils/StringToNumber.h>

void GPS::actualizar(){
    std::string datos = controladorGPSMockup->getInformation();
    StringTokenizer tokens(datos, ",");
    if(tokens.nextToken().compare("$PGRMC")){
        std::string tiempo = tokens.nextToken(); // Time of fix 22:54:46 UTC
        parsearTiempo(tiempo, &hora, &minuto, &segundo);
        if(tokens.nextToken().compare("A")){
            latitud = StringToNumber<float>(tokens.nextToken());
            N = tokens.nextToken().compare("N");
            longitud = StringToNumber<float>(tokens.nextToken());
            W = tokens.nextToken().compare("W");
            tokens.nextToken(); //Speed over ground, Knots
            tokens.nextToken(); //Course Made Good, True
            std::string fecha = tokens.nextToken(); //Date of fix  19 November 1994
            parsearTiempo(fecha, &dia, &mes, &anio);
            tokens.nextToken(); //Magnetic variation 20.3 deg East
            tokens.nextToken(); //mandatory checksum
        }
    }
}

void GPS::parsearTiempo(std::string tiempo, uint8_t *horaDia, uint8_t *minutoMes, uint8_t *sengundoAnio){
    *horaDia = StringToNumber<uint8_t>(tiempo.substr(0,2));
    *minutoMes = StringToNumber<uint8_t>(tiempo.substr(2,4));
    *sengundoAnio = StringToNumber<uint8_t>(tiempo.substr(4,6));
}

uint8_t GPS::getHora(){
    return hora;
}

uint8_t GPS::getMinuto(){
    return hora;
}

uint8_t GPS::getSegundo(){
    return hora;
}

uint8_t GPS::getDia(){
    return hora;
}

uint8_t GPS::getMes(){
    return hora;
}

uint8_t GPS::getAnio(){
    return hora;
}

GPS::~GPS(){
    delete controladorGPSMockup;
}

