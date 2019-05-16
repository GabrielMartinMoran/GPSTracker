#include <gtest/gtest.h>
#include <GPSControllerMockup.h>
#include <GPS.h>

TEST(GPS, posicionesValidas)
{
    GPSControllerMockup *gpsControllerMockup = new GPSControllerMockup();
    GPS *gps = new GPS(gpsControllerMockup);
    gps->actualizar();

    float esperado;
    float obtenido;

    esperado = -3751.65;
    obtenido = gps->getLatitud();

    EXPECT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;

    esperado = -14507.36;
    obtenido = gps->getLongitud();

    EXPECT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;

    EXPECT_TRUE(gps->actualizar());

    esperado = stringToNumber<float>("3654.9279999999999"); //hay algo raro aca
    obtenido = gps->getLatitud();

    EXPECT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;

    esperado = 7302.5;
    obtenido = gps->getLongitud();

    EXPECT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;

    EXPECT_TRUE(gps->actualizar());

    esperado = stringToNumber<float>("3654.9270000000001");
    obtenido = gps->getLatitud();

    EXPECT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;

    esperado = 7302.5020000000004;
    obtenido = gps->getLongitud();

    EXPECT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;

    EXPECT_TRUE(gps->actualizar());

    esperado = stringToNumber<float>("3654.925");
    obtenido = gps->getLatitud();

    EXPECT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;

    esperado = 7302.5029296875;
    obtenido = gps->getLongitud();

    EXPECT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;

    EXPECT_TRUE(gps->actualizar());

    EXPECT_FALSE(gps->actualizar());

    EXPECT_TRUE(gps->actualizar());

    delete gpsControllerMockup;
    delete gps;
}

TEST(GPS, getHora)
{
    GPSControllerMockup *gpsControllerMockup = new GPSControllerMockup();
    GPS *gps = new GPS(gpsControllerMockup);
    gps->actualizar();
    int esperado = 8;
    int obtenido = gps->getHora();
    EXPECT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;
    delete gpsControllerMockup;
    delete gps;
}

TEST(GPS, getMinuto)
{
    GPSControllerMockup *gpsControllerMockup = new GPSControllerMockup();
    GPS *gps = new GPS(gpsControllerMockup);
    gps->actualizar();
    int esperado = 18;
    int obtenido = gps->getMinuto();
    EXPECT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;
    delete gpsControllerMockup;
    delete gps;
}

TEST(GPS, getSegundo)
{
    GPSControllerMockup *gpsControllerMockup = new GPSControllerMockup();
    GPS *gps = new GPS(gpsControllerMockup);
    gps->actualizar();
    int esperado = 36;
    int obtenido = gps->getSegundo();
    EXPECT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;
    delete gpsControllerMockup;
    delete gps;
}

TEST(GPS, getDia)
{
    GPSControllerMockup *gpsControllerMockup = new GPSControllerMockup();
    GPS *gps = new GPS(gpsControllerMockup);
    gps->actualizar();
    int esperado = 13;
    int obtenido = gps->getDia();
    EXPECT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;
    delete gpsControllerMockup;
    delete gps;
}

TEST(GPS, getMes)
{
    GPSControllerMockup *gpsControllerMockup = new GPSControllerMockup();
    GPS *gps = new GPS(gpsControllerMockup);
    gps->actualizar();
    int esperado = 9;
    int obtenido = gps->getMes();
    EXPECT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;
    delete gpsControllerMockup;
    delete gps;
}

TEST(GPS, getAnio)
{
    GPSControllerMockup *gpsControllerMockup = new GPSControllerMockup();
    GPS *gps = new GPS(gpsControllerMockup);
    gps->actualizar();
    int esperado = 98;
    int obtenido = gps->getAnio();
    EXPECT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;
    delete gpsControllerMockup;
    delete gps;
}

TEST(GPS, getLatitud)
{
    GPSControllerMockup *gpsControllerMockup = new GPSControllerMockup();
    GPS *gps = new GPS(gpsControllerMockup);
    gps->actualizar();
    float esperado = -3751.65;
    float obtenido = gps->getLatitud();
    EXPECT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;
    delete gpsControllerMockup;
    delete gps;
}

TEST(GPS, getLongitud)
{
    GPSControllerMockup *gpsControllerMockup = new GPSControllerMockup();
    GPS *gps = new GPS(gpsControllerMockup);
    gps->actualizar();
    float esperado = -14507.36;
    float obtenido = gps->getLongitud();
    EXPECT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;
    delete gpsControllerMockup;
    delete gps;
}