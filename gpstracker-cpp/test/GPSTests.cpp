#include <gtest/gtest.h>
#include <GPSControllerMockup.h>
#include <GPSControllerMockup2.h>
#include <GPS/GPS.h>

TEST(GPS, motionless)
{
    unsigned int metersBetweenPoints = 10;
    GPSControllerMockup2 *gpsControllerMockup = new GPSControllerMockup2();
    GPS *gps = new GPS(gpsControllerMockup, metersBetweenPoints);

    double esperado;
    double obtenido;

    //"$GPRMC,054457,A,3654.928,N,07302.500,W,41.7,2.65,160519,,E*47"
    EXPECT_TRUE(gps->updated());
    EXPECT_EQ("$GPRMC,054457,A,3654.928,N,07302.500,W,41.7,2.65,160519,,E*40", gps->getGPSData()->getRawData());
    EXPECT_EQ("19-05-16 05:44:57,+036.91547,-073.04167,0\n", gps->getGPSData()->getNormalizedData());
    EXPECT_TRUE(gps->updated());
    EXPECT_EQ("$GPRMC,054457,A,3654.928,N,07302.500,W,41.7,2.65,160519,,E*40", gps->getGPSData()->getRawData());
    EXPECT_EQ("19-05-16 05:44:57,+036.91547,-073.04167,1\n", gps->getGPSData()->getNormalizedData());
    EXPECT_TRUE(gps->updated());
    EXPECT_EQ("$GPRMC,054509,A,3654.923,N,07302.506,W,51.1,2.54,160519,,E*42", gps->getGPSData()->getRawData());
    EXPECT_EQ("19-05-16 05:45:09,+036.91538,-073.04177,0\n", gps->getGPSData()->getNormalizedData());

    delete gpsControllerMockup;
    delete gps;
}

TEST(GPS, posicionesValidas)
{
    unsigned int metersBetweenPoints = 2;
    GPSControllerMockup *gpsControllerMockup = new GPSControllerMockup();
    GPS *gps = new GPS(gpsControllerMockup, metersBetweenPoints);

    double esperado;
    double obtenido;

    //"$GPRMC,054457,A,3654.928,N,07302.500,W,41.7,2.65,160519,,E*47"
    EXPECT_TRUE(gps->updated());
    EXPECT_EQ("$GPRMC,054457,A,3654.928,N,07302.500,W,41.7,2.65,160519,,E*40", gps->getGPSData()->getRawData());
    esperado = (36 + 54.928 / 60);

    obtenido = gps->getGPSData()->getCoordinate().getLatitude();

    EXPECT_DOUBLE_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                         << "obtenido: " << obtenido;

    esperado = -1 * (73 + 02.5 / 60);
    obtenido = gps->getGPSData()->getCoordinate().getLongitude();

    EXPECT_DOUBLE_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                         << "obtenido: " << obtenido;

    //"$GPRMC,054509,A,3654.923,N,07302.506,W,51.1,2.54,160519,,E*42"
    EXPECT_TRUE(gps->updated());

    esperado = 36 + 54.923 / 60;
    obtenido = gps->getGPSData()->getCoordinate().getLatitude();

    EXPECT_DOUBLE_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                         << "obtenido: " << obtenido;

    esperado = -1 * (73 + 02.506 / 60);
    obtenido = gps->getGPSData()->getCoordinate().getLongitude();

    EXPECT_DOUBLE_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                         << "obtenido: " << obtenido;

    //"$GPRMC,054454.529,V,3654.929,N,07302.499,W,9.6,2.63,160519,,E*7F"
    //""
    EXPECT_FALSE(gps->updated()); //porque no dataWaiting

    //esperado = 36 + 54.929 / 60;
    //obtenido = gps->getGPSData()->getCoordinate().getLatitude();

    //espero lo mismo que el de antes
    EXPECT_DOUBLE_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                         << "obtenido: " << obtenido;

    //esperado = -1 *(73 + 02.499 / 60);
    //obtenido = gps->getGPSData()->getCoordinate().getLongitude();

    //espero lo mismo que el de antes
    EXPECT_DOUBLE_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                         << "obtenido: " << obtenido;

    //"$GPRMC,054457,A,3654.928,N,07302.500,W,41.7,2.65,160519,,E*40"
    EXPECT_TRUE(gps->updated());

    esperado = 36 + 54.928 / 60;
    obtenido = gps->getGPSData()->getCoordinate().getLatitude();

    EXPECT_DOUBLE_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                         << "obtenido: " << obtenido;

    esperado = -1 * (73 + 02.500 / 60);
    obtenido = gps->getGPSData()->getCoordinate().getLongitude();

    EXPECT_DOUBLE_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                         << "obtenido: " << obtenido;

    //"$GPRMC,054500,A,3654.907,N,07302.482,W,75.7,2.56,160519,,E*42"
    EXPECT_TRUE(gps->updated());

    esperado = 36 + 54.907 / 60;
    obtenido = gps->getGPSData()->getCoordinate().getLatitude();

    EXPECT_DOUBLE_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                         << "obtenido: " << obtenido;

    esperado = -1 * (73 + 02.482 / 60);
    obtenido = gps->getGPSData()->getCoordinate().getLongitude();

    EXPECT_DOUBLE_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                         << "obtenido: " << obtenido;

    //"$GPRMC,054503,A,3654.925,N,07302.503,W,82.8,2.57,160519,,E*4F"
    EXPECT_TRUE(gps->updated());
    EXPECT_EQ(gps->getGPSData()->getRawData(), "$GPRMC,054503,A,3654.925,N,07302.503,W,82.8,2.57,160519,,E*4F");

    esperado = 36 + 54.925 / 60;
    obtenido = gps->getGPSData()->getCoordinate().getLatitude();

    EXPECT_DOUBLE_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                         << "obtenido: " << obtenido;

    esperado = -1 * (73 + 02.503 / 60);
    obtenido = gps->getGPSData()->getCoordinate().getLongitude();

    EXPECT_DOUBLE_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                         << "obtenido: " << obtenido;

    EXPECT_FALSE(gps->updated());

    //lo mismo de antes
    EXPECT_EQ(gps->getGPSData()->getRawData(), "$GPRMC,054503,A,3654.925,N,07302.503,W,82.8,2.57,160519,,E*4F");

    //esperado = 36 + 54.925 / 60;
    //obtenido = gps->getGPSData()->getCoordinate().getLatitude();

    EXPECT_DOUBLE_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                         << "obtenido: " << obtenido;

    //esperado = -1 *(73 + 02.503 / 60);
    //obtenido = gps->getGPSData()->getCoordinate().getLongitude();

    EXPECT_DOUBLE_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                         << "obtenido: " << obtenido;

    //"$GPRMC,054509,A,3654.923,N,07302.506,W,51.1,2.54,160519,,E*42"
    EXPECT_TRUE(gps->updated());

    esperado = 36 + 54.923 / 60;
    obtenido = gps->getGPSData()->getCoordinate().getLatitude();

    EXPECT_DOUBLE_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                         << "obtenido: " << obtenido;

    esperado = -1 * (73 + 02.506 / 60);
    obtenido = gps->getGPSData()->getCoordinate().getLongitude();

    EXPECT_DOUBLE_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                         << "obtenido: " << obtenido;

    delete gpsControllerMockup;
    delete gps;
}

TEST(GPS, getHour)
{
    unsigned int metersBetweenPoints = 2;
    //"$GPRMC,054457,A,3654.928,N,07302.500,W,41.7,2.65,160519,,E*47"
    GPSControllerMockup *gpsControllerMockup = new GPSControllerMockup();
    GPS *gps = new GPS(gpsControllerMockup, metersBetweenPoints);
    EXPECT_TRUE(gps->updated());
    int esperado = 5;
    int obtenido = gps->getGPSData()->getDateTime().getHour();
    EXPECT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;
    delete gpsControllerMockup;
    delete gps;
}

TEST(GPS, getMinute)
{
    unsigned int metersBetweenPoints = 2;
    //"$GPRMC,054457,A,3654.928,N,07302.500,W,41.7,2.65,160519,,E*47"
    GPSControllerMockup *gpsControllerMockup = new GPSControllerMockup();
    GPS *gps = new GPS(gpsControllerMockup, metersBetweenPoints);
    gps->updated();
    int esperado = 44;
    int obtenido = gps->getGPSData()->getDateTime().getMinute();
    EXPECT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;
    delete gpsControllerMockup;
    delete gps;
}

TEST(GPS, getSecond)
{
    unsigned int metersBetweenPoints = 2;
    //"$GPRMC,054457,A,3654.928,N,07302.500,W,41.7,2.65,160519,,E*47"
    GPSControllerMockup *gpsControllerMockup = new GPSControllerMockup();
    GPS *gps = new GPS(gpsControllerMockup, metersBetweenPoints);
    gps->updated();
    int esperado = 57;
    int obtenido = gps->getGPSData()->getDateTime().getSecond();
    EXPECT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;
    delete gpsControllerMockup;
    delete gps;
}

TEST(GPS, getDay)
{
    unsigned int metersBetweenPoints = 2;
    //"$GPRMC,054457,A,3654.928,N,07302.500,W,41.7,2.65,160519,,E*47"
    GPSControllerMockup *gpsControllerMockup = new GPSControllerMockup();
    GPS *gps = new GPS(gpsControllerMockup, metersBetweenPoints);
    gps->updated();
    int esperado = 16;
    int obtenido = gps->getGPSData()->getDateTime().getDay();
    EXPECT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;
    delete gpsControllerMockup;
    delete gps;
}

TEST(GPS, getMonth)
{
    unsigned int metersBetweenPoints = 2;
    //"$GPRMC,054457,A,3654.928,N,07302.500,W,41.7,2.65,160519,,E*47"
    GPSControllerMockup *gpsControllerMockup = new GPSControllerMockup();
    GPS *gps = new GPS(gpsControllerMockup, metersBetweenPoints);
    gps->updated();
    int esperado = 5;
    int obtenido = gps->getGPSData()->getDateTime().getMonth();
    EXPECT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;
    delete gpsControllerMockup;
    delete gps;
}

TEST(GPS, getYear)
{
    unsigned int metersBetweenPoints = 2;
    //"$GPRMC,054457,A,3654.928,N,07302.500,W,41.7,2.65,160519,,E*47"
    GPSControllerMockup *gpsControllerMockup = new GPSControllerMockup();
    GPS *gps = new GPS(gpsControllerMockup, metersBetweenPoints);
    gps->updated();
    int esperado = 19;
    int obtenido = gps->getGPSData()->getDateTime().getYear();
    EXPECT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;
    delete gpsControllerMockup;
    delete gps;
}

TEST(GPS, getLatitude)
{
    unsigned int metersBetweenPoints = 2;
    //"$GPRMC,054457,A,3654.928,N,07302.500,W,41.7,2.65,160519,,E*47"
    GPSControllerMockup *gpsControllerMockup = new GPSControllerMockup();
    GPS *gps = new GPS(gpsControllerMockup, metersBetweenPoints);
    gps->updated();
    double esperado = (36 + 54.928 / 60);
    double obtenido = gps->getGPSData()->getCoordinate().getLatitude();
    EXPECT_DOUBLE_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                         << "obtenido: " << obtenido;
    delete gpsControllerMockup;
    delete gps;
}

TEST(GPS, getLongitude)
{
    unsigned int metersBetweenPoints = 2;
    //"$GPRMC,054457,A,3654.928,N,07302.500,W,41.7,2.65,160519,,E*47"
    GPSControllerMockup *gpsControllerMockup = new GPSControllerMockup();
    GPS *gps = new GPS(gpsControllerMockup, metersBetweenPoints);
    gps->updated();
    double esperado = -1 * (73 + 02.5 / 60);
    double obtenido = gps->getGPSData()->getCoordinate().getLongitude();
    EXPECT_DOUBLE_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                         << "obtenido: " << obtenido;
    delete gpsControllerMockup;
    delete gps;
}