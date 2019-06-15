#include <gtest/gtest.h>
#include <GPS/Coordenada.h>

TEST(Coordenadas, Coordenadas)
{
    double latitud;
    double longitud;
    double esperado;
    double obtenido;

    latitud = 51.5007;
    longitud = 0.1246;

    Coordenada c = Coordenada(latitud, longitud);

    esperado = latitud;
    obtenido = c.getLatitud();
    ASSERT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;

    esperado = longitud;
    obtenido = c.getLongitud();
    ASSERT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;
}

TEST(Coordenadas, InvalidCoordinateExeption)
{

    double latitud;
    double longitud;

    latitud = 251.5007;
    longitud = 0.1246;

    EXPECT_THROW(Coordenada(latitud, longitud), InvalidCoordinateException);

    longitud = 251.5007;
    latitud = 0.1246;

    EXPECT_THROW(Coordenada(latitud, longitud), InvalidCoordinateException);

    latitud = -251.5007;
    longitud = 0.1246;

    EXPECT_THROW(Coordenada(latitud, longitud), InvalidCoordinateException);

    longitud = -251.5007;
    latitud = 0.1246;

    EXPECT_THROW(Coordenada(latitud, longitud), InvalidCoordinateException);

    longitud = 151.5007;
    latitud = 0.1246;

    EXPECT_NO_THROW(Coordenada(latitud, longitud));
}