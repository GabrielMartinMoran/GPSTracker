#include <GPS/GPSData.h>

GPSData::GPSData(std::string data) : rawData(data)
{
    StringTokenizer *tokens = new StringTokenizer(data, ",");
    std::string *tiempo = nullptr;
    std::string *fecha = nullptr;
    try
    {
        if (tokens->nextToken() == "$GPRMC")
        {
            tiempo = new std::string(tokens->nextToken()); // 08:18:36 UTC
            unsigned int hora, minuto, segundo;
            parsearTiempo(tiempo, &hora, &minuto, &segundo);

            if (tokens->nextToken() == std::string("A"))
            {
                double latitud = parsearCoordenada(tokens->nextToken());

                if (tokens->nextToken() == std::string("S"))
                {
                    latitud *= -1;
                }

                double longitud = parsearCoordenada(tokens->nextToken());

                if (tokens->nextToken() == std::string("E"))
                {
                    longitud *= -1;
                }
                delete this->coordenada;
                this->coordenada = new Coordenada(latitud, longitud);

                tokens->nextToken();

                tokens->nextToken(); //Course Made Good, True

                fecha = new std::string(tokens->nextToken()); //13 Sep 1998
                unsigned int dia, mes, anio;
                parsearTiempo(fecha, &dia, &mes, &anio);
                
                delete this->date_time;
                this->date_time = new DateTime(dia, mes, anio, hora, minuto, segundo);
                tokens->nextToken(); //Magnetic variation 20.3 deg East

                tokens->nextToken(); //mandatory checksum
                this->valido = true;
            }
        }
    }
    catch (NoMoreTokensException)
    {
        this->valido = false;
    }

    delete tokens;
    delete fecha;
    delete tiempo;
}
void GPSData::parsearTiempo(std::string *tiempo, unsigned int *horaDia, unsigned int *minutoMes, unsigned int *sengundoAnio)
{
    *horaDia = stringToNumber<unsigned int>(tiempo->substr(0, 2));
    *minutoMes = stringToNumber<unsigned int>(tiempo->substr(2, 2));
    *sengundoAnio = stringToNumber<unsigned int>(tiempo->substr(4, 2));
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
    return *this->date_time;
}

Coordenada GPSData::getCoordenada()
{
    return *this->coordenada;
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
    unsigned int t = 41;
    char *buffer = new char[t];
    snprintf(buffer, t,"%02d-%02d-%02d %02d:%02d:%02d,%c%09.5f,%c%09.5f\n",
            dateTime().getAnio(), dateTime().getMes(), dateTime().getDia(),
            dateTime().getHora(), dateTime().getMinuto(), dateTime().getSegundo(),
            getCoordenada().getLatitud() > 0 ? '+' : '-',
            std::abs(getCoordenada().getLatitud()),
            getCoordenada().getLongitud() > 0 ? '+' : '-',
            std::abs(getCoordenada().getLongitud()));
    return std::string(buffer);
}

GPSData::~GPSData()
{
}