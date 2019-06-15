#include <GPS/GPSData.h>

GPSData::GPSData(std::string data)
{
    this->rawData = std::string(data);

    std::string sentencias;
    std::string checksum;

    StringTokenizer dataTokens = StringTokenizer(data, "*");
    try
    {
        sentencias = dataTokens.nextToken();
        checksum = dataTokens.nextToken();

        if (calculateChecksum(sentencias) == checksum)
        {
            StringTokenizer sentenciasTokens = StringTokenizer(sentencias, ",");

            std::string tiempo;
            std::string fecha;
            std::string latitud_s;
            std::string longitud_s;

            if (sentenciasTokens.nextToken() == "$GPRMC")
            {
                tiempo = std::string(sentenciasTokens.nextToken()); // 08:18:36 UTC
                unsigned int hora, minuto, segundo;
                parsearTiempo(tiempo, &hora, &minuto, &segundo);

                if (sentenciasTokens.nextToken() == "A")
                {
                    latitud_s = std::string(sentenciasTokens.nextToken());
                    double latitud = parsearCoordenada(latitud_s);

                    if (sentenciasTokens.nextToken() == "S")
                    {
                        latitud *= -1;
                    }
                    longitud_s = std::string(sentenciasTokens.nextToken());
                    double longitud = parsearCoordenada(longitud_s);

                    if (sentenciasTokens.nextToken() == "W")
                    {
                        longitud *= -1;
                    }

                    this->coordenada = new Coordenada(latitud, longitud);

                    sentenciasTokens.nextToken();

                    sentenciasTokens.nextToken(); //Course Made Good, True

                    fecha = std::string(sentenciasTokens.nextToken()); //13 Sep 1998

                    unsigned int dia, mes, anio;
                    parsearTiempo(fecha, &dia, &mes, &anio);

                    this->date_time = new DateTime(dia, mes, anio, hora, minuto, segundo);
                    sentenciasTokens.nextToken(); //Magnetic variation 20.3 deg

                    sentenciasTokens.nextToken(); //East
                }
            }
        }
        else
        {
            invalidar();
        }
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
        invalidar();
    }
}

std::string GPSData::calculateChecksum(std::string sentencias)
{
    const char *s = sentencias.c_str();
    s++;
    int c = 0;

    while (*s)
        c ^= *s++;

    unsigned int t = 3;
    char buffer[t];
    snprintf(buffer, t, "%X", c);

    return std::string(buffer);
}

void GPSData::invalidar()
{
    delete this->coordenada;
    this->coordenada = nullptr;

    delete this->date_time;
    this->date_time = nullptr;
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
    if (!this->isValido())
    {
        throw InvalidReadGPSDataException();
    }
    return *this->date_time;
}

Coordenada GPSData::getCoordenada()
{
    if (!this->isValido())
    {
        throw InvalidReadGPSDataException();
    }
    return *this->coordenada;
}

bool GPSData::isValido()
{
    return this->coordenada != nullptr && this->date_time != nullptr;
}

void GPSData::inmovil()
{
    this->_inmovil = true;
}

bool GPSData::isInmovil()
{
    if (!this->isValido())
    {
        throw InvalidReadGPSDataException();
    }
    return this->_inmovil;
}

std::string GPSData::getRawData()
{
    return this->rawData;
}

std::string GPSData::getNormalizedData()
{
    if (!this->isValido())
    {
        throw InvalidReadGPSDataException();
    }
    unsigned int t = 43;
    char buffer[t];
    snprintf(buffer, t, "%02d-%02d-%02d %02d:%02d:%02d,%c%09.5f,%c%09.5f,%c\n",
             dateTime().getAnio(), dateTime().getMes(), dateTime().getDia(),
             dateTime().getHora(), dateTime().getMinuto(), dateTime().getSegundo(),
             getCoordenada().getLatitud() > 0 ? '+' : '-',
             std::abs(getCoordenada().getLatitud()),
             getCoordenada().getLongitud() > 0 ? '+' : '-',
             std::abs(getCoordenada().getLongitud()),
             this->isInmovil() ? '1' : '0');
    return std::string(buffer);
}

GPSData::~GPSData()
{
    delete this->coordenada;
    delete this->date_time;
}