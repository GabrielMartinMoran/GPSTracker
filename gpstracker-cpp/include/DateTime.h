#ifndef DateTime_h
#define DateTime_h

class DateTime
{
private:
    int hora = 0;
    int minuto = 0;
    int segundo = 0;
    int dia = 0;
    int mes = 0;
    int anio = 0;

public:
    DateTime(int dia, int mes, int anio, int hora, int minuto, int segundo);
    int getDia();
    int getMes();
    int getAnio();
    int getHora();
    int getMinuto();
    int getSegundo();
    ~DateTime();
};
#endif