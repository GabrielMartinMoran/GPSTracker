#include "GPS.h"

void GPS::actualizar()
{
    String datos = controladorGPSMockup->leerInformacion();
    StringTokenizer tokens(datos, ",");
    if (tokens.nextToken() == "$PGRMC")
    {
        String tiempo = tokens.nextToken(); // Time of fix 22:54:46 UTC
        parsearTiempo(tiempo, &hora, &minuto, &segundo);
        if (tokens.nextToken() == "A")
        {
            latitud = tokens.nextToken().toFloat();
            N = tokens.nextToken() == "N";
            longitud = tokens.nextToken().toFloat();
            W = tokens.nextToken() == "W";
            tokens.nextToken();                //Speed over ground, Knots
            tokens.nextToken();                //Course Made Good, True
            String fecha = tokens.nextToken(); //Date of fix  19 November 1994
            parsearTiempo(fecha, &dia, &mes, &anio);
            tokens.nextToken(); //Magnetic variation 20.3 deg East
            tokens.nextToken(); //mandatory checksum
        }
    }
}

void GPS::parsearTiempo(String tiempo, byte *horaDia, byte *minutoMes, byte *sengundoAnio)
{
    *horaDia = (byte)tiempo.substring(0, 2).toInt();
    *minutoMes = (byte)tiempo.substring(2, 4).toInt();
    *sengundoAnio = (byte)tiempo.substring(4, 6).toInt();
}

byte GPS::getHora()
{
    return hora;
}

byte GPS::getMinuto()
{
    return hora;
}

byte GPS::getSegundo()
{
    return hora;
}

byte GPS::getDia()
{
    return hora;
}

byte GPS::getMes()
{
    return hora;
}

byte GPS::getAnio()
{
    return hora;
}

GPS::~GPS()
{
    delete controladorGPSMockup;
}
