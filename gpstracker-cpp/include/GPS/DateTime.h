#ifndef DateTime_h
#define DateTime_h

#include <exceptions/InvalidDateException.ex>
#include <exceptions/InvalidTimeException.ex>

class DateTime
{
private:
    unsigned int hora = 0;
    unsigned int minuto = 0;
    unsigned int segundo = 0;
    unsigned int dia = 0;
    unsigned int mes = 0;
    unsigned int anio = 0;

public:
    DateTime(unsigned int dia, unsigned int mes, unsigned int anio, unsigned int hora, unsigned int minuto, unsigned int segundo);
    unsigned int getDia();
    unsigned int getMes();
    unsigned int getAnio();
    unsigned int getHora();
    unsigned int getMinuto();
    unsigned int getSegundo();
    ~DateTime();
};
#endif