#include <gtest/gtest.h>
#include <GPS/DateTime.h>

TEST(DateTime, Coordenadas)
{
    unsigned int hora;
    unsigned int minuto;
    unsigned int segundo;
    unsigned int dia;
    unsigned int mes;
    unsigned int anio;

    unsigned int esperado;
    unsigned int obtenido;

    hora = 1;
    minuto = 1;
    segundo = 1;
    dia = 1;
    mes = 1;
    anio = 1;

    DateTime c = DateTime(dia, mes, anio, hora, minuto, segundo);

    esperado = dia;
    obtenido = c.getDia();
    ASSERT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;

    esperado = mes;
    obtenido = c.getMes();
    ASSERT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;

    esperado = anio;
    obtenido = c.getAnio();
    ASSERT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;

    esperado = hora;
    obtenido = c.getHora();
    ASSERT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;

    esperado = minuto;
    obtenido = c.getMinuto();
    ASSERT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;

    esperado = segundo;
    obtenido = c.getSegundo();
    ASSERT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;
}

TEST(DateTime, InvalidTimeException)
{

    unsigned int hora;
    unsigned int minuto;
    unsigned int segundo;
    unsigned int dia;
    unsigned int mes;
    unsigned int anio;

    hora = 24;
    minuto = 1;
    segundo = 1;
    dia = 1;
    mes = 1;
    anio = 1;

    EXPECT_THROW(DateTime(dia, mes, anio, hora, minuto, segundo), InvalidTimeException);

    hora = 1;
    minuto = 60;
    segundo = 1;
    dia = 1;
    mes = 1;
    anio = 1;

    EXPECT_THROW(DateTime(dia, mes, anio, hora, minuto, segundo), InvalidTimeException);

    hora = 1;
    minuto = 1;
    segundo = 60;
    dia = 1;
    mes = 1;
    anio = 1;

    EXPECT_THROW(DateTime(dia, mes, anio, hora, minuto, segundo), InvalidTimeException);

    hora = 1;
    minuto = 1;
    segundo = 1;
    dia = 1;
    mes = 1;
    anio = 1;

    EXPECT_NO_THROW(DateTime(dia, mes, anio, hora, minuto, segundo));
}

TEST(DateTime, InvalidDateException)
{

    unsigned int hora;
    unsigned int minuto;
    unsigned int segundo;
    unsigned int dia;
    unsigned int mes;
    unsigned int anio;

    hora = 1;
    minuto = 1;
    segundo = 1;
    dia = 0;
    mes = 1;
    anio = 1;

    EXPECT_THROW(DateTime(dia, mes, anio, hora, minuto, segundo), InvalidDateException);

    hora = 1;
    minuto = 1;
    segundo = 1;
    dia = 32;
    mes = 1;
    anio = 1;

    EXPECT_THROW(DateTime(dia, mes, anio, hora, minuto, segundo), InvalidDateException);

    hora = 1;
    minuto = 1;
    segundo = 1;
    dia = 1;
    mes = 0;
    anio = 1;

    EXPECT_THROW(DateTime(dia, mes, anio, hora, minuto, segundo), InvalidDateException);

    hora = 1;
    minuto = 1;
    segundo = 1;
    dia = 1;
    mes = 13;
    anio = 1;

    EXPECT_THROW(DateTime(dia, mes, anio, hora, minuto, segundo), InvalidDateException);

    hora = 1;
    minuto = 1;
    segundo = 1;
    dia = 31;
    mes = 1;
    anio = 1;

    EXPECT_NO_THROW(DateTime(dia, mes, anio, hora, minuto, segundo));

    hora = 1;
    minuto = 1;
    segundo = 1;
    dia = 29;
    mes = 2;
    anio = 1;

    EXPECT_THROW(DateTime(dia, mes, anio, hora, minuto, segundo), InvalidDateException);

    hora = 1;
    minuto = 1;
    segundo = 1;
    dia = 31;
    mes = 3;
    anio = 1;

    EXPECT_NO_THROW(DateTime(dia, mes, anio, hora, minuto, segundo));

    hora = 1;
    minuto = 1;
    segundo = 1;
    dia = 31;
    mes = 4;
    anio = 1;

    EXPECT_THROW(DateTime(dia, mes, anio, hora, minuto, segundo), InvalidDateException);

    hora = 1;
    minuto = 1;
    segundo = 1;
    dia = 31;
    mes = 5;
    anio = 1;

    EXPECT_NO_THROW(DateTime(dia, mes, anio, hora, minuto, segundo));

    hora = 1;
    minuto = 1;
    segundo = 1;
    dia = 31;
    mes = 6;
    anio = 1;

    EXPECT_THROW(DateTime(dia, mes, anio, hora, minuto, segundo), InvalidDateException);

    hora = 1;
    minuto = 1;
    segundo = 1;
    dia = 31;
    mes = 7;
    anio = 1;

    EXPECT_NO_THROW(DateTime(dia, mes, anio, hora, minuto, segundo));

    hora = 1;
    minuto = 1;
    segundo = 1;
    dia = 31;
    mes = 8;
    anio = 1;

    EXPECT_NO_THROW(DateTime(dia, mes, anio, hora, minuto, segundo));

    hora = 1;
    minuto = 1;
    segundo = 1;
    dia = 31;
    mes = 9;
    anio = 1;

    EXPECT_THROW(DateTime(dia, mes, anio, hora, minuto, segundo), InvalidDateException);

    hora = 1;
    minuto = 1;
    segundo = 1;
    dia = 31;
    mes = 10;
    anio = 1;

    EXPECT_NO_THROW(DateTime(dia, mes, anio, hora, minuto, segundo));

    hora = 1;
    minuto = 1;
    segundo = 1;
    dia = 31;
    mes = 11;
    anio = 1;

    EXPECT_THROW(DateTime(dia, mes, anio, hora, minuto, segundo), InvalidDateException);

    hora = 1;
    minuto = 1;
    segundo = 1;
    dia = 31;
    mes = 12;
    anio = 1;

    EXPECT_NO_THROW(DateTime(dia, mes, anio, hora, minuto, segundo));

    hora = 1;
    minuto = 1;
    segundo = 1;
    dia = 1;
    mes = 1;
    anio = 1;

    EXPECT_NO_THROW(DateTime(dia, mes, anio, hora, minuto, segundo));
}