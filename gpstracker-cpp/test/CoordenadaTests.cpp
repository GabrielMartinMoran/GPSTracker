#include <gtest/gtest.h>
#include <GPS/Coordinate.h>

TEST(Coordenadas, Coordenadas)
{
    double latitude;
    double longitude;
    double esperado;
    double obtenido;

    latitude = 51.5007;
    longitude = 0.1246;

    Coordinate c = Coordinate(latitude, longitude);

    esperado = latitude;
    obtenido = c.getLatitude();
    ASSERT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;

    esperado = longitude;
    obtenido = c.getLongitude();
    ASSERT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;
}

TEST(Coordenadas, InvalidCoordinateExeption)
{

    double latitude;
    double longitude;

    latitude = 251.5007;
    longitude = 0.1246;

    EXPECT_THROW(Coordinate(latitude, longitude), InvalidCoordinateException);

    longitude = 251.5007;
    latitude = 0.1246;

    EXPECT_THROW(Coordinate(latitude, longitude), InvalidCoordinateException);

    latitude = -251.5007;
    longitude = 0.1246;

    EXPECT_THROW(Coordinate(latitude, longitude), InvalidCoordinateException);

    longitude = -251.5007;
    latitude = 0.1246;

    EXPECT_THROW(Coordinate(latitude, longitude), InvalidCoordinateException);

    longitude = 151.5007;
    latitude = 0.1246;

    EXPECT_NO_THROW(Coordinate(latitude, longitude));
}