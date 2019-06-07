#include <gtest/gtest.h>
#include <GPSControllerMockup.h>
#include <GPS/GPS.h>
/*
TEST(GPS, posicionesValidas)
{
    GPSControllerMockup *gpsControllerMockup = new GPSControllerMockup();
    GPS *gps = new GPS(gpsControllerMockup);

    double esperado;
    double obtenido;

    EXPECT_TRUE(gps->actualizado());
    //"$GPRMC,081836,A,3751.65,S,14507.36,E,000.0,360.0,130998,011.3,E*62"
    esperado = -1 * (37 + 51.65 / 60);
    
    obtenido = gps->getGPSData().getCoordenada().getLatitud();

    EXPECT_DOUBLE_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                         << "obtenido: " << obtenido;
    /*
    esperado = (145 + 07.36 / 60);
    obtenido = gps->getGPSData().getCoordenada().getLongitud();

    EXPECT_DOUBLE_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                         << "obtenido: " << obtenido;
    /*
    //"$GPRMC,054454.529,V,3654.929,N,07302.499,W,9.6,2.63,160519,,E*7F"
    EXPECT_FALSE(gps->actualizado());

    /*esperado = 36 + 54.929 / 60;
    obtenido = gps->getGPSData().getCoordenada().getLatitud();

    EXPECT_DOUBLE_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                         << "obtenido: " << obtenido;

    esperado = -1 *(73 + 02.499 / 60);
    obtenido = gps->getGPSData().getCoordenada().getLongitud();

    EXPECT_DOUBLE_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                         << "obtenido: " << obtenido;
    //lo de arriba no va
    //"$GPRMC,054457.529,A,3654.928,N,07302.500,W,41.7,2.65,160519,,E*47"
    EXPECT_TRUE(gps->actualizado());

    esperado = 36 + 54.928 / 60;
    obtenido = gps->getGPSData().getCoordenada().getLatitud();

    EXPECT_DOUBLE_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                         << "obtenido: " << obtenido;

    esperado = -1 *(73 + 02.500 / 60);
    obtenido = gps->getGPSData().getCoordenada().getLongitud();

    EXPECT_DOUBLE_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                         << "obtenido: " << obtenido;

    //"$GPRMC,054500.529,A,3654.927,N,07302.502,W,75.7,2.56,160519,,E*4E"
    EXPECT_FALSE(gps->actualizado());

    /*esperado = 36 + 54.927 / 60;
    obtenido = gps->getGPSData().getCoordenada().getLatitud();

    EXPECT_DOUBLE_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                         << "obtenido: " << obtenido;

    esperado = -1 *(73 + 02.502 / 60);
    obtenido = gps->getGPSData().getCoordenada().getLongitud();

    EXPECT_DOUBLE_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                         << "obtenido: " << obtenido;
    //lo de arriba no va
    //"$GPRMC,054503.529,A,3654.925,N,07302.503,W,82.8,2.57,160519,,E*48"
    EXPECT_TRUE(gps->actualizado());

    //"$GPRMC,054506.529,V,3654.924,N,07302.504,W,63.9,2.51,160519,,E*43"
    EXPECT_FALSE(gps->actualizado());

    //"$GPRMC,054509.529,A,3654.923,N,07302.506,W,51.1,2.54,160519,,E*45"
    EXPECT_TRUE(gps->actualizado());
    
    delete gpsControllerMockup;
    delete gps;
}

TEST(GPS, getHora)
{
    //"$GPRMC,081836,A,3751.65,S,14507.36,E,000.0,360.0,130998,011.3,E*62"
    GPSControllerMockup *gpsControllerMockup = new GPSControllerMockup();
    GPS *gps = new GPS(gpsControllerMockup);
    EXPECT_TRUE(gps->actualizado());
    int esperado = 8;
    int obtenido = gps->getGPSData().dateTime().getHora();
    EXPECT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;
    delete gpsControllerMockup;
    delete gps;
}

TEST(GPS, getMinuto)
{
    //"$GPRMC,081836,A,3751.65,S,14507.36,E,000.0,360.0,130998,011.3,E*62"
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
    //"$GPRMC,081836,A,3751.65,S,14507.36,E,000.0,360.0,130998,011.3,E*62"
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
    //"$GPRMC,081836,A,3751.65,S,14507.36,E,000.0,360.0,130998,011.3,E*62"
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
    //"$GPRMC,081836,A,3751.65,S,14507.36,E,000.0,360.0,130998,011.3,E*62"
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
    //"$GPRMC,081836,A,3751.65,S,14507.36,E,000.0,360.0,130998,011.3,E*62"
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
    //"$GPRMC,081836,A,3751.65,S,14507.36,E,000.0,360.0,130998,011.3,E*62"
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
    //"$GPRMC,081836,A,3751.65,S,14507.36,E,000.0,360.0,130998,011.3,E*62"
    GPSControllerMockup *gpsControllerMockup = new GPSControllerMockup();
    GPS *gps = new GPS(gpsControllerMockup);
    gps->actualizado();
    double esperado = (145 + 07.36 / 60);
    double obtenido = gps->getGPSData().getCoordenada().getLongitud();
    EXPECT_DOUBLE_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                         << "obtenido: " << obtenido;
    delete gpsControllerMockup;
    delete gps;
}*/