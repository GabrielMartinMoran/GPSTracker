#include <gtest/gtest.h>
#include <GPS/DateTime.h>

TEST(DateTime, Coordenadas)
{
    unsigned int hour;
    unsigned int minute;
    unsigned int second;
    unsigned int day;
    unsigned int month;
    unsigned int year;

    unsigned int esperado;
    unsigned int obtenido;

    hour = 1;
    minute = 1;
    second = 1;
    day = 1;
    month = 1;
    year = 1;

    DateTime c = DateTime(day, month, year, hour, minute, second);

    esperado = day;
    obtenido = c.getDay();
    ASSERT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;

    esperado = month;
    obtenido = c.getMonth();
    ASSERT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;

    esperado = year;
    obtenido = c.getYear();
    ASSERT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;

    esperado = hour;
    obtenido = c.getHour();
    ASSERT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;

    esperado = minute;
    obtenido = c.getMinute();
    ASSERT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;

    esperado = second;
    obtenido = c.getSecond();
    ASSERT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;
}

TEST(DateTime, InvalidTimeException)
{

    unsigned int hour;
    unsigned int minute;
    unsigned int second;
    unsigned int day;
    unsigned int month;
    unsigned int year;

    hour = 24;
    minute = 1;
    second = 1;
    day = 1;
    month = 1;
    year = 1;

    EXPECT_THROW(DateTime(day, month, year, hour, minute, second), InvalidTimeException);

    hour = 1;
    minute = 60;
    second = 1;
    day = 1;
    month = 1;
    year = 1;

    EXPECT_THROW(DateTime(day, month, year, hour, minute, second), InvalidTimeException);

    hour = 1;
    minute = 1;
    second = 60;
    day = 1;
    month = 1;
    year = 1;

    EXPECT_THROW(DateTime(day, month, year, hour, minute, second), InvalidTimeException);

    hour = 1;
    minute = 1;
    second = 1;
    day = 1;
    month = 1;
    year = 1;

    EXPECT_NO_THROW(DateTime(day, month, year, hour, minute, second));
}

TEST(DateTime, InvalidDateException)
{

    unsigned int hour;
    unsigned int minute;
    unsigned int second;
    unsigned int day;
    unsigned int month;
    unsigned int year;

    hour = 1;
    minute = 1;
    second = 1;
    day = 0;
    month = 1;
    year = 1;

    EXPECT_THROW(DateTime(day, month, year, hour, minute, second), InvalidDateException);

    hour = 1;
    minute = 1;
    second = 1;
    day = 32;
    month = 1;
    year = 1;

    EXPECT_THROW(DateTime(day, month, year, hour, minute, second), InvalidDateException);

    hour = 1;
    minute = 1;
    second = 1;
    day = 1;
    month = 0;
    year = 1;

    EXPECT_THROW(DateTime(day, month, year, hour, minute, second), InvalidDateException);

    hour = 1;
    minute = 1;
    second = 1;
    day = 1;
    month = 13;
    year = 1;

    EXPECT_THROW(DateTime(day, month, year, hour, minute, second), InvalidDateException);

    hour = 1;
    minute = 1;
    second = 1;
    day = 31;
    month = 1;
    year = 1;

    EXPECT_NO_THROW(DateTime(day, month, year, hour, minute, second));

    hour = 1;
    minute = 1;
    second = 1;
    day = 29;
    month = 2;
    year = 1;

    EXPECT_THROW(DateTime(day, month, year, hour, minute, second), InvalidDateException);

    hour = 1;
    minute = 1;
    second = 1;
    day = 31;
    month = 3;
    year = 1;

    EXPECT_NO_THROW(DateTime(day, month, year, hour, minute, second));

    hour = 1;
    minute = 1;
    second = 1;
    day = 31;
    month = 4;
    year = 1;

    EXPECT_THROW(DateTime(day, month, year, hour, minute, second), InvalidDateException);

    hour = 1;
    minute = 1;
    second = 1;
    day = 31;
    month = 5;
    year = 1;

    EXPECT_NO_THROW(DateTime(day, month, year, hour, minute, second));

    hour = 1;
    minute = 1;
    second = 1;
    day = 31;
    month = 6;
    year = 1;

    EXPECT_THROW(DateTime(day, month, year, hour, minute, second), InvalidDateException);

    hour = 1;
    minute = 1;
    second = 1;
    day = 31;
    month = 7;
    year = 1;

    EXPECT_NO_THROW(DateTime(day, month, year, hour, minute, second));

    hour = 1;
    minute = 1;
    second = 1;
    day = 31;
    month = 8;
    year = 1;

    EXPECT_NO_THROW(DateTime(day, month, year, hour, minute, second));

    hour = 1;
    minute = 1;
    second = 1;
    day = 31;
    month = 9;
    year = 1;

    EXPECT_THROW(DateTime(day, month, year, hour, minute, second), InvalidDateException);

    hour = 1;
    minute = 1;
    second = 1;
    day = 31;
    month = 10;
    year = 1;

    EXPECT_NO_THROW(DateTime(day, month, year, hour, minute, second));

    hour = 1;
    minute = 1;
    second = 1;
    day = 31;
    month = 11;
    year = 1;

    EXPECT_THROW(DateTime(day, month, year, hour, minute, second), InvalidDateException);

    hour = 1;
    minute = 1;
    second = 1;
    day = 31;
    month = 12;
    year = 1;

    EXPECT_NO_THROW(DateTime(day, month, year, hour, minute, second));

    hour = 1;
    minute = 1;
    second = 1;
    day = 1;
    month = 1;
    year = 1;

    EXPECT_NO_THROW(DateTime(day, month, year, hour, minute, second));
}