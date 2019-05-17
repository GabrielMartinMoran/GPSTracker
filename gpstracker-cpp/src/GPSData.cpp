#include <GPSData.h>

GPSData::GPSData(std::string data)
{
    try
    {
        StringTokenizer tokens(data, ",");
        if (tokens.nextToken() == "$GPRMC")
        {
            std::string tiempo = tokens.nextToken(); // 08:18:36 UTC
            parsearTiempo(tiempo, &(this->hora), &(this->minuto), &(this->segundo));
            if (tokens.nextToken() == std::string("A"))
            {

                this->latitud = stringToNumber<float>(tokens.nextToken());

                if (tokens.nextToken() == std::string("S"))
                {
                    this->latitud *= -1;
                }

                this->longitud = stringToNumber<float>(tokens.nextToken());

                if (tokens.nextToken() == std::string("E"))
                {
                    this->longitud *= -1;
                }

                tokens.nextToken();

                tokens.nextToken(); //Course Made Good, True

                std::string fecha = tokens.nextToken(); //13 Sep 1998
                parsearTiempo(fecha, &(this->dia), &(this->mes), &(this->anio));

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
void GPSData::parsearTiempo(std::string tiempo, int *horaDia, int *minutoMes, int *sengundoAnio)
{
    *horaDia = stringToNumber<int>(tiempo.substr(0, 2));
    *minutoMes = stringToNumber<int>(tiempo.substr(2, 2));
    *sengundoAnio = stringToNumber<int>(tiempo.substr(4, 2));
}
int GPSData::getHora()
{
    return this->hora;
}

int GPSData::getMinuto()
{
    return this->minuto;
}

int GPSData::getSegundo()
{
    return this->segundo;
}

int GPSData::getDia()
{
    return this->dia;
}

int GPSData::getMes()
{
    return this->mes;
}

int GPSData::getAnio()
{
    return this->anio;
}

float GPSData::getLatitud()
{
    return this->latitud;
}
float GPSData::getLongitud()
{
    return this->longitud;
}
bool GPSData::isValido()
{
    return this->valido;
}
GPSData::~GPSData()
{
}