#include <gtest/gtest.h>
#include <GPSControllerMockup.h>
#include <GPS/GPS.h>

TEST(GPS, posicionesValidas)
{
    GPSControllerMockup *gpsControllerMockup = new GPSControllerMockup();
    GPS *gps = new GPS(gpsControllerMockup);

    double esperado;
    double obtenido;

    //"$GPRMC,054457,A,3654.928,N,07302.500,W,41.7,2.65,160519,,E*47"
    EXPECT_TRUE(gps->actualizado());
    EXPECT_EQ("$GPRMC,054457,A,3654.928,N,07302.500,W,41.7,2.65,160519,,E*47",gps->getGPSData().getRawData());
    esperado = (36 + 54.928 / 60);
    
    obtenido = gps->getGPSData().getCoordenada().getLatitud();

    EXPECT_DOUBLE_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                         << "obtenido: " << obtenido;
    
    esperado = -1 * (73 + 02.5 / 60);
    obtenido = gps->getGPSData().getCoordenada().getLongitud();

    EXPECT_DOUBLE_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                         << "obtenido: " << obtenido;
    
    //"$GPRMC,054509,A,3654.923,N,07302.506,W,51.1,2.54,160519,,E*45"
    EXPECT_TRUE(gps->actualizado());

    esperado = 36 + 54.923 / 60;
    obtenido = gps->getGPSData().getCoordenada().getLatitud();

    EXPECT_DOUBLE_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                         << "obtenido: " << obtenido;

    esperado = -1 *(73 + 02.506 / 60);
    obtenido = gps->getGPSData().getCoordenada().getLongitud();

    EXPECT_DOUBLE_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                         << "obtenido: " << obtenido;

    //"$GPRMC,054454.529,V,3654.929,N,07302.499,W,9.6,2.63,160519,,E*7F"
    //""
    EXPECT_FALSE(gps->actualizado()); //porque no dataWaiting

    //esperado = 36 + 54.929 / 60;
    //obtenido = gps->getGPSData().getCoordenada().getLatitud();

    //espero lo mismo que el de antes
    EXPECT_DOUBLE_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                         << "obtenido: " << obtenido;

    //esperado = -1 *(73 + 02.499 / 60);
    //obtenido = gps->getGPSData().getCoordenada().getLongitud();

    //espero lo mismo que el de antes
    EXPECT_DOUBLE_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                         << "obtenido: " << obtenido;

    //"$GPRMC,054457,A,3654.928,N,07302.500,W,41.7,2.65,160519,,E*47"
    EXPECT_TRUE(gps->actualizado());

    esperado = 36 + 54.928 / 60;
    obtenido = gps->getGPSData().getCoordenada().getLatitud();

    EXPECT_DOUBLE_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                         << "obtenido: " << obtenido;

    esperado = -1 *(73 + 02.500 / 60);
    obtenido = gps->getGPSData().getCoordenada().getLongitud();

    EXPECT_DOUBLE_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                         << "obtenido: " << obtenido;

    //"$GPRMC,054500,A,3654.907,N,07302.482,W,75.7,2.56,160519,,E*4E"
    EXPECT_TRUE(gps->actualizado());

    esperado = 36 + 54.907 / 60;
    obtenido = gps->getGPSData().getCoordenada().getLatitud();

    EXPECT_DOUBLE_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                         << "obtenido: " << obtenido;

    esperado = -1 *(73 + 02.482 / 60);
    obtenido = gps->getGPSData().getCoordenada().getLongitud();

    EXPECT_DOUBLE_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                         << "obtenido: " << obtenido;


    //"$GPRMC,054503,A,3654.925,N,07302.503,W,82.8,2.57,160519,,E*48"
    EXPECT_TRUE(gps->actualizado());
    EXPECT_EQ(gps->getGPSData().getRawData(),"$GPRMC,054503,A,3654.925,N,07302.503,W,82.8,2.57,160519,,E*48");

    esperado = 36 + 54.925 / 60;
    obtenido = gps->getGPSData().getCoordenada().getLatitud();

    EXPECT_DOUBLE_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                         << "obtenido: " << obtenido;

    esperado = -1 *(73 + 02.503 / 60);
    obtenido = gps->getGPSData().getCoordenada().getLongitud();

    EXPECT_DOUBLE_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                         << "obtenido: " << obtenido;

    EXPECT_FALSE(gps->actualizado());
    
    //lo mismo de antes
    EXPECT_EQ(gps->getGPSData().getRawData(),"$GPRMC,054503,A,3654.925,N,07302.503,W,82.8,2.57,160519,,E*48");

    //esperado = 36 + 54.925 / 60;
    //obtenido = gps->getGPSData().getCoordenada().getLatitud();

    EXPECT_DOUBLE_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                         << "obtenido: " << obtenido;

    //esperado = -1 *(73 + 02.503 / 60);
    //obtenido = gps->getGPSData().getCoordenada().getLongitud();

    EXPECT_DOUBLE_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                         << "obtenido: " << obtenido;
    
    //"$GPRMC,054509,A,3654.923,N,07302.506,W,51.1,2.54,160519,,E*45"
    EXPECT_TRUE(gps->actualizado());

    esperado = 36 + 54.923 / 60;
    obtenido = gps->getGPSData().getCoordenada().getLatitud();

    EXPECT_DOUBLE_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                         << "obtenido: " << obtenido;

    esperado = -1 *(73 + 02.506 / 60);
    obtenido = gps->getGPSData().getCoordenada().getLongitud();

    EXPECT_DOUBLE_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                         << "obtenido: " << obtenido;
    
    delete gpsControllerMockup;
    delete gps;
}

TEST(GPS, getHora)
{
    //"$GPRMC,054457,A,3654.928,N,07302.500,W,41.7,2.65,160519,,E*47"
    GPSControllerMockup *gpsControllerMockup = new GPSControllerMockup();
    GPS *gps = new GPS(gpsControllerMockup);
    EXPECT_TRUE(gps->actualizado());
    int esperado = 5;
    int obtenido = gps->getGPSData().dateTime().getHora();
    EXPECT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;
    delete gpsControllerMockup;
    delete gps;
}

TEST(GPS, getMinuto)
{
    //"$GPRMC,054457,A,3654.928,N,07302.500,W,41.7,2.65,160519,,E*47"
    GPSControllerMockup *gpsControllerMockup = new GPSControllerMockup();
    GPS *gps = new GPS(gpsControllerMockup);
    gps->actualizado();
    int esperado = 44;
    int obtenido = gps->getGPSData().dateTime().getMinuto();
    EXPECT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;
    delete gpsControllerMockup;
    delete gps;
}

TEST(GPS, getSegundo)
{
    //"$GPRMC,054457,A,3654.928,N,07302.500,W,41.7,2.65,160519,,E*47"
    GPSControllerMockup *gpsControllerMockup = new GPSControllerMockup();
    GPS *gps = new GPS(gpsControllerMockup);
    gps->actualizado();
    int esperado = 57;
    int obtenido = gps->getGPSData().dateTime().getSegundo();
    EXPECT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;
    delete gpsControllerMockup;
    delete gps;
}

TEST(GPS, getDia)
{
    //"$GPRMC,054457,A,3654.928,N,07302.500,W,41.7,2.65,160519,,E*47"
    GPSControllerMockup *gpsControllerMockup = new GPSControllerMockup();
    GPS *gps = new GPS(gpsControllerMockup);
    gps->actualizado();
    int esperado = 16;
    int obtenido = gps->getGPSData().dateTime().getDia();
    EXPECT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;
    delete gpsControllerMockup;
    delete gps;
}

TEST(GPS, getMes)
{
    //"$GPRMC,054457,A,3654.928,N,07302.500,W,41.7,2.65,160519,,E*47"
    GPSControllerMockup *gpsControllerMockup = new GPSControllerMockup();
    GPS *gps = new GPS(gpsControllerMockup);
    gps->actualizado();
    int esperado = 5;
    int obtenido = gps->getGPSData().dateTime().getMes();
    EXPECT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;
    delete gpsControllerMockup;
    delete gps;
}

TEST(GPS, getAnio)
{
    //"$GPRMC,054457,A,3654.928,N,07302.500,W,41.7,2.65,160519,,E*47"
    GPSControllerMockup *gpsControllerMockup = new GPSControllerMockup();
    GPS *gps = new GPS(gpsControllerMockup);
    gps->actualizado();
    int esperado = 19;
    int obtenido = gps->getGPSData().dateTime().getAnio();
    EXPECT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;
    delete gpsControllerMockup;
    delete gps;
}

TEST(GPS, getLatitud)
{
    //"$GPRMC,054457,A,3654.928,N,07302.500,W,41.7,2.65,160519,,E*47"
    GPSControllerMockup *gpsControllerMockup = new GPSControllerMockup();
    GPS *gps = new GPS(gpsControllerMockup);
    gps->actualizado();
    double esperado = (36 + 54.928 / 60);
    double obtenido = gps->getGPSData().getCoordenada().getLatitud();
    EXPECT_DOUBLE_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                         << "obtenido: " << obtenido;
    delete gpsControllerMockup;
    delete gps;
}

TEST(GPS, getLongitud)
{
    //"$GPRMC,054457,A,3654.928,N,07302.500,W,41.7,2.65,160519,,E*47"
    GPSControllerMockup *gpsControllerMockup = new GPSControllerMockup();
    GPS *gps = new GPS(gpsControllerMockup);
    gps->actualizado();
    double esperado = -1 * (73 + 02.5 / 60);
    double obtenido = gps->getGPSData().getCoordenada().getLongitud();
    EXPECT_DOUBLE_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                         << "obtenido: " << obtenido;
    delete gpsControllerMockup;
    delete gps;
}