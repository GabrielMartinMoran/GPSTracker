#include <DateTime.h>

DateTime::DateTime(int dia, int mes, int anio, int hora, int minuto, int segundo) : dia(dia), mes(mes), anio(anio), hora(hora), minuto(minuto), segundo(segundo) {}

int DateTime::getHora()
{
    return this->hora;
}

int DateTime::getMinuto()
{
    return this->minuto;
}

int DateTime::getSegundo()
{
    return this->segundo;
}

int DateTime::getDia()
{
    return this->dia;
}

int DateTime::getMes()
{
    return this->mes;
}

int DateTime::getAnio()
{
    return this->anio;
}

DateTime::~DateTime() {
}