#include <gtest/gtest.h>
#include <GPSControllerMockup.h>
#include <GPS/GPS.h>

TEST(GPS, posicionesValidas)
{
    GPSControllerMockup *gpsControllerMockup = new GPSControllerMockup();
    GPS *gps = new GPS(gpsControllerMockup);
    gps->actualizado();

    double esperado;
    double obtenido;

    esperado = -1 * (37 + 51.65 / 60);
    obtenido = gps->getGPSData().getCoordenada().getLatitud();

    EXPECT_DOUBLE_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                         << "obtenido: " << obtenido;

    esperado = -1 * (145 + 07.36 / 60);
    obtenido = gps->getGPSData().getCoordenada().getLongitud();

    EXPECT_DOUBLE_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                         << "obtenido: " << obtenido;

    EXPECT_TRUE(gps->actualizado());

    esperado = 36 + 54.9279999999999 / 60;
    obtenido = gps->getGPSData().getCoordenada().getLatitud();

    EXPECT_DOUBLE_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                         << "obtenido: " << obtenido;

    esperado = 73 + 02.5 / 60;
    obtenido = gps->getGPSData().getCoordenada().getLongitud();

    EXPECT_DOUBLE_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                         << "obtenido: " << obtenido;

    EXPECT_TRUE(gps->actualizado());

    esperado = 36 + 54.9270000000001 / 60;
    obtenido = gps->getGPSData().getCoordenada().getLatitud();

    EXPECT_DOUBLE_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                         << "obtenido: " << obtenido;

    esperado = 73 + 02.5020000000004 / 60;
    obtenido = gps->getGPSData().getCoordenada().getLongitud();

    EXPECT_DOUBLE_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                         << "obtenido: " << obtenido;

    EXPECT_TRUE(gps->actualizado());

    esperado = 36 + 54.925 / 60;
    obtenido = gps->getGPSData().getCoordenada().getLatitud();

    EXPECT_DOUBLE_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                         << "obtenido: " << obtenido;

    esperado = 73 + 02.5029999999997 / 60;
    obtenido = gps->getGPSData().getCoordenada().getLongitud();

    EXPECT_DOUBLE_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                         << "obtenido: " << obtenido;

    EXPECT_TRUE(gps->actualizado());

    EXPECT_FALSE(gps->actualizado());

    EXPECT_TRUE(gps->actualizado());

    delete gpsControllerMockup;
    delete gps;
}

TEST(GPS, getHora)
{
    GPSControllerMockup *gpsControllerMockup = new GPSControllerMockup();
    GPS *gps = new GPS(gpsControllerMockup);
    gps->actualizado();
    int esperado = 8;
    int obtenido = gps->getGPSData().dateTime().getHora();
    EXPECT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;
    delete gpsControllerMockup;
    delete gps;
}

TEST(GPS, getMinuto)
{
    GPSControllerMockup *gpsControllerMockup = new GPSControllerMockup();
    GPS *gps = new GPS(gpsControllerMockup);
    gps->actualizado();
    int esperado = 18;
    int obtenido = gps->getGPSData().dateTime().getMinuto();
    EXPECT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;
    delete gpsControllerMockup;
    delete gps;
}

TEST(GPS, getSegundo)
{
    GPSControllerMockup *gpsControllerMockup = new GPSControllerMockup();
    GPS *gps = new GPS(gpsControllerMockup);
    gps->actualizado();
    int esperado = 36;
    int obtenido = gps->getGPSData().dateTime().getSegundo();
    EXPECT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;
    delete gpsControllerMockup;
    delete gps;
}

TEST(GPS, getDia)
{
    GPSControllerMockup *gpsControllerMockup = new GPSControllerMockup();
    GPS *gps = new GPS(gpsControllerMockup);
    gps->actualizado();
    int esperado = 13;
    int obtenido = gps->getGPSData().dateTime().getDia();
    EXPECT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;
    delete gpsControllerMockup;
    delete gps;
}

TEST(GPS, getMes)
{
    GPSControllerMockup *gpsControllerMockup = new GPSControllerMockup();
    GPS *gps = new GPS(gpsControllerMockup);
    gps->actualizado();
    int esperado = 9;
    int obtenido = gps->getGPSData().dateTime().getMes();
    EXPECT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;
    delete gpsControllerMockup;
    delete gps;
}

TEST(GPS, getAnio)
{
    GPSControllerMockup *gpsControllerMockup = new GPSControllerMockup();
    GPS *gps = new GPS(gpsControllerMockup);
    gps->actualizado();
    int esperado = 98;
    int obtenido = gps->getGPSData().dateTime().getAnio();
    EXPECT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;
    delete gpsControllerMockup;
    delete gps;
}

TEST(GPS, getLatitud)
{
    GPSControllerMockup *gpsControllerMockup = new GPSControllerMockup();
    GPS *gps = new GPS(gpsControllerMockup);
    gps->actualizado();
    double esperado = -1 * (37 + 51.65 / 60);
    double obtenido = gps->getGPSData().getCoordenada().getLatitud();
    EXPECT_DOUBLE_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                         << "obtenido: " << obtenido;
    delete gpsControllerMockup;
    delete gps;
}

TEST(GPS, getLongitud)
{
    GPSControllerMockup *gpsControllerMockup = new GPSControllerMockup();
    GPS *gps = new GPS(gpsControllerMockup);
    gps->actualizado();
    double esperado = -1 * (145 + 07.36 / 60);
    double obtenido = gps->getGPSData().getCoordenada().getLongitud();
    EXPECT_DOUBLE_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                         << "obtenido: " << obtenido;
    delete gpsControllerMockup;
    delete gps;
}