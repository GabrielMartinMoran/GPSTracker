#include <GPS/GPSData.h>

GPSData::GPSData(std::string data) : rawData(data)
{
    try
    {
        StringTokenizer tokens(data, ",");
        if (tokens.nextToken() == "$GPRMC")
        {
            std::string tiempo = tokens.nextToken(); // 08:18:36 UTC
            unsigned int hora, minuto, segundo;
            parsearTiempo(tiempo, &hora, &minuto, &segundo);

            if (tokens.nextToken() == std::string("A"))
            {
                double latitud = parsearCoordenada(tokens.nextToken());

                if (tokens.nextToken() == std::string("S"))
                {
                    latitud *= -1;
                }

                double longitud = parsearCoordenada(tokens.nextToken());

                if (tokens.nextToken() == std::string("E"))
                {
                    longitud *= -1;
                }

                this->coordenada = Coordenada(latitud, longitud);

                tokens.nextToken();

                tokens.nextToken(); //Course Made Good, True

                std::string fecha = tokens.nextToken(); //13 Sep 1998
                unsigned int dia, mes, anio;
                parsearTiempo(fecha, &dia, &mes, &anio);

                this->date_time = DateTime(dia, mes, anio, hora, minuto, segundo);
                tokens.nextToken(); //Magnetic variation 20.3 deg East

                tokens.nextToken(); //mandatory checksum
                this->valido = true;
                return;
            }
        }
    }
    catch (NoMoreTokensException)
    {
        this->valido = false;
    }
}
void GPSData::parsearTiempo(std::string tiempo, unsigned int *horaDia, unsigned int *minutoMes, unsigned int *sengundoAnio)
{
    *horaDia = stringToNumber<unsigned int>(tiempo.substr(0, 2));
    *minutoMes = stringToNumber<unsigned int>(tiempo.substr(2, 2));
    *sengundoAnio = stringToNumber<unsigned int>(tiempo.substr(4, 2));
}

double GPSData::parsearCoordenada(std::string coordenada)
{
    int separador = coordenada.find(".") - 2;
    double grados = stringToNumber<double>(coordenada.substr(0, separador));
    double minutos = stringToNumber<double>(coordenada.substr(separador, coordenada.length() - separador));
    return grados + minutos / 60;
}

DateTime GPSData::dateTime()
{
    return this->date_time;
}

Coordenada GPSData::getCoordenada()
{
    return this->coordenada;
}

bool GPSData::isValido()
{
    return this->valido;
}

std::string GPSData::getRawData()
{
    return this->rawData;
}

std::string GPSData::getNormalizedData()
{
    unsigned int anio = dateTime().getAnio();
    unsigned int mes = dateTime().getMes();
    unsigned int dia = dateTime().getDia();
    unsigned int hora = dateTime().getHora();
    unsigned int minuto = dateTime().getMinuto();
    unsigned int segundo = dateTime().getSegundo();
    double latitud = getCoordenada().getLatitud();
    char signoLatitud;
    if(latitud > 0){
        signoLatitud = '+';
    }else{
        signoLatitud = '-';
        latitud *= -1;
    }
    double longitud = getCoordenada().getLongitud();
    char signoLongitud;
    if(longitud > 0){
        signoLongitud = '+';
    }else{
        signoLongitud = '-';
        longitud *= -1;
    }
    char buffer[40];
    sprintf(buffer, "%02d-%02d-%02d %02d:%02d:%02d,%c%09.5f,%c%09.5f\n", anio, mes, dia, hora, minuto, segundo, signoLatitud, latitud, signoLongitud, longitud);
    return std::string(buffer);
}

GPSData::~GPSData()
{
}