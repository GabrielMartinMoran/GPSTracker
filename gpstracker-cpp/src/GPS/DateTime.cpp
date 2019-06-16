#include <GPS/DateTime.h>

DateTime::DateTime(unsigned int dia, unsigned int mes, unsigned int anio, unsigned int hora, unsigned int minuto, unsigned int segundo)
{

    if (hora > 23 || minuto > 59 || segundo > 59)
    {
        throw InvalidTimeException();
    }
    if (mes < 1 || mes > 12)
    {
        throw InvalidDateException();
    }
    unsigned int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (dia < 1 || dia > monthDays[mes - 1])
    {
        throw InvalidDateException();
    }

    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
    this->hora = hora;
    this->minuto = minuto;
    this->segundo = segundo;
}

unsigned int DateTime::getHora()
{
    return this->hora;
}

unsigned int DateTime::getMinuto()
{
    return this->minuto;
}

unsigned int DateTime::getSegundo()
{
    return this->segundo;
}

unsigned int DateTime::getDia()
{
    return this->dia;
}

unsigned int DateTime::getMes()
{
    return this->mes;
}

unsigned int DateTime::getAnio()
{
    return this->anio;
}

DateTime::~DateTime()
{
}