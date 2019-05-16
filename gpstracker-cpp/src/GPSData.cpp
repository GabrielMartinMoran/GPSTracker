#include <GPSData.h>

GPSData::GPSData(std::string data)
{
    StringTokenizer tokens(data, ",");
    if (tokens.hasNext())
    {
        if (tokens.nextToken() == "$GPRMC")
        {
            if (tokens.hasNext())
            {
                std::string tiempo = tokens.nextToken(); // 08:18:36 UTC
                parsearTiempo(tiempo, &(this->hora), &(this->minuto), &(this->segundo));
                if (tokens.hasNext())
                {
                    if (tokens.nextToken() == std::string("A"))
                    {
                        if (tokens.hasNext())
                        {
                            this->latitud = stringToNumber<double>(tokens.nextToken());
                            if (tokens.hasNext())
                            {
                                if (tokens.nextToken() == std::string("S"))
                                {
                                    this->latitud *= -1;
                                }
                                if (tokens.hasNext())
                                {
                                    this->longitud = stringToNumber<double>(tokens.nextToken());
                                    if (tokens.hasNext())
                                    {
                                        if (tokens.nextToken() == std::string("E"))
                                        {
                                            this->longitud *= -1;
                                        }
                                        if (tokens.hasNext())
                                        {
                                            tokens.nextToken();
                                            if (tokens.hasNext())
                                            {
                                                tokens.nextToken(); //Course Made Good, True
                                                if (tokens.hasNext())
                                                {
                                                    std::string fecha = tokens.nextToken(); //13 Sep 1998
                                                    parsearTiempo(fecha, &(this->dia), &(this->mes), &(this->anio));
                                                    if (tokens.hasNext()) //Speed over ground, Knots
                                                    {
                                                        tokens.nextToken(); //Magnetic variation 20.3 deg East
                                                        if (tokens.hasNext())
                                                        {
                                                            tokens.nextToken(); //mandatory checksum
                                                            this->valido = true;
                                                            return;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    this->valido = false;
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

double GPSData::getLatitud()
{
    return this->latitud;
}
double GPSData::getLongitud()
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