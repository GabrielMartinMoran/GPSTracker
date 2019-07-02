#include <gtest/gtest.h>
#include <GPS/GPSData.h>

TEST(GPSData, normalizedData)
{
    std::string data;
    std::string esperado;
    std::string obtenido;
    GPSData *gpsData;

    data = "$GPRMC,081836,A,3751.65,S,14507.36,E,000.0,360.0,130998,011.3,E*62";
    gpsData = new GPSData(data);
    EXPECT_EQ(gpsData->getRawData(), data);
    esperado = "98-09-13 08:18:36,-037.86083,+145.12267,0\n";
    obtenido = gpsData->getNormalizedData();
    EXPECT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;
    delete gpsData;

    data = "$GPRMC,221315,A,3751.65,N,14507.36,W,000.0,360.0,150418,011.3,E*6C";
    gpsData = new GPSData(data);
    EXPECT_EQ(gpsData->getRawData(), data);
    esperado = "18-04-15 22:13:15,+037.86083,-145.12267,0\n";
    obtenido = gpsData->getNormalizedData();
    EXPECT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;
    delete gpsData;

    data = "$GPRMC,000000,A,3751.65,S,14507.36,W,000.0,360.0,010100,011.3,E*7E";
    gpsData = new GPSData(data);
    EXPECT_EQ(gpsData->getRawData(), data);
    esperado = "00-01-01 00:00:00,-037.86083,-145.12267,0\n";
    obtenido = gpsData->getNormalizedData();
    EXPECT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;
    delete gpsData;

    data = "$GPRMC,000000,A,3751.65,N,14507.36,E,000.0,360.0,010100,011.3,E*71";
    gpsData = new GPSData(data);
    EXPECT_EQ(gpsData->getRawData(), data);
    esperado = "00-01-01 00:00:00,+037.86083,+145.12267,0\n";
    obtenido = gpsData->getNormalizedData();
    EXPECT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;
    delete gpsData;
}

TEST(GPSData, normalizedDataInmovil)
{
    std::string data;
    std::string esperado;
    std::string obtenido;
    GPSData *gpsData;

    data = "$GPRMC,081836,A,3751.65,S,14507.36,E,000.0,360.0,130998,011.3,E*62";
    gpsData = new GPSData(data);
    EXPECT_EQ(gpsData->getRawData(), data);
    gpsData->motionless();
    esperado = "98-09-13 08:18:36,-037.86083,+145.12267,1\n";
    obtenido = gpsData->getNormalizedData();
    EXPECT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;
    delete gpsData;

    data = "$GPRMC,221315,A,3751.65,N,14507.36,W,000.0,360.0,150418,011.3,E*6C";
    gpsData = new GPSData(data);
    EXPECT_EQ(gpsData->getRawData(), data);
    gpsData->motionless();
    esperado = "18-04-15 22:13:15,+037.86083,-145.12267,1\n";
    obtenido = gpsData->getNormalizedData();
    EXPECT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;
    delete gpsData;

    data = "$GPRMC,000000,A,3751.65,S,14507.36,W,000.0,360.0,010100,011.3,E*7E";
    gpsData = new GPSData(data);
    EXPECT_EQ(gpsData->getRawData(), data);
    gpsData->motionless();
    esperado = "00-01-01 00:00:00,-037.86083,-145.12267,1\n";
    obtenido = gpsData->getNormalizedData();
    EXPECT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;
    delete gpsData;

    data = "$GPRMC,000000,A,3751.65,N,14507.36,E,000.0,360.0,010100,011.3,E*71";
    gpsData = new GPSData(data);
    EXPECT_EQ(gpsData->getRawData(), data);
    gpsData->motionless();
    esperado = "00-01-01 00:00:00,+037.86083,+145.12267,1\n";
    obtenido = gpsData->getNormalizedData();
    EXPECT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;
    delete gpsData;
}

TEST(GPSData, rawData)
{
    std::string data = "$GPRMC,081836,A,3751.65,S,14507.36,E,000.0,360.0,130998,011.3,E*62";
    GPSData *gpsData = new GPSData(data);
    std::string esperado = data;
    std::string obtenido = gpsData->getRawData();
    EXPECT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;
    delete gpsData;
}

TEST(GPSData, sentenciaCompleta)
{
    std::string data;
    GPSData *gpsData;
    bool esperado = true;
    bool obtenido;

    data = "$GPRMC,062359.00,A,3436.59962,S,05833.36400,W,1.430,,150619,,,A*77";
    gpsData = new GPSData(data);
    obtenido = gpsData->isValid();
    EXPECT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;

    int esperadoINT;
    int obtenidoINT;

    //hora
    esperadoINT = 6;
    obtenidoINT = gpsData->getDateTime().getHour();
    EXPECT_EQ(esperadoINT, obtenidoINT) << "esperado: " << esperadoINT << "\n"
                                        << "obtenido: " << obtenidoINT;

    //minute
    esperadoINT = 23;
    obtenidoINT = gpsData->getDateTime().getMinute();
    EXPECT_EQ(esperadoINT, obtenidoINT) << "esperado: " << esperadoINT << "\n"
                                        << "obtenido: " << obtenidoINT;

    //second
    esperadoINT = 59;
    obtenidoINT = gpsData->getDateTime().getSecond();
    EXPECT_EQ(esperadoINT, obtenidoINT) << "esperado: " << esperadoINT << "\n"
                                        << "obtenido: " << obtenidoINT;

    //day
    esperadoINT = 15;
    obtenidoINT = gpsData->getDateTime().getDay();
    EXPECT_EQ(esperadoINT, obtenidoINT) << "esperado: " << esperadoINT << "\n"
                                        << "obtenido: " << obtenidoINT;

    //month
    esperadoINT = 6;
    obtenidoINT = gpsData->getDateTime().getMonth();
    EXPECT_EQ(esperadoINT, obtenidoINT) << "esperado: " << esperadoINT << "\n"
                                        << "obtenido: " << obtenidoINT;

    //year
    esperadoINT = 19;
    obtenidoINT = gpsData->getDateTime().getYear();
    EXPECT_EQ(esperadoINT, obtenidoINT) << "esperado: " << esperadoINT << "\n"
                                        << "obtenido: " << obtenidoINT;

    double esperadoDOUBLE;
    double obtenidoDOUBLE;

    //latitud 3436.59962 S
    esperadoDOUBLE = -1 * (34 + 36.59962 / 60);
    obtenidoDOUBLE = gpsData->getCoordinate().getLatitude();
    EXPECT_DOUBLE_EQ(esperadoDOUBLE, obtenidoDOUBLE) << "esperado: " << esperadoDOUBLE << "\n"
                                                     << "obtenido: " << obtenidoDOUBLE;

    //longitud 05833.36400 W
    esperadoDOUBLE = -1 * (58 + 33.36400 / 60);
    obtenidoDOUBLE = gpsData->getCoordinate().getLongitude();
    EXPECT_DOUBLE_EQ(esperadoDOUBLE, obtenidoDOUBLE) << "esperado: " << esperadoDOUBLE << "\n"
                                                     << "obtenido: " << obtenidoDOUBLE;

    delete gpsData;
}

TEST(GPSData, valido)
{
    std::string data;
    GPSData *gpsData;
    bool esperado = true;
    bool obtenido;

    data = "$GPRMC,054457,A,3654.928,N,07302.500,W,41.7,2.65,160519,,E*40";
    gpsData = new GPSData(data);
    obtenido = gpsData->isValid();
    EXPECT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;
    delete gpsData;

    data = "$GPRMC,081836,A,3751.65,S,14507.36,E,000.0,360.0,130998,011.3,E*62";
    gpsData = new GPSData(data);
    obtenido = gpsData->isValid();
    EXPECT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;
    delete gpsData;
}

TEST(GPSData, invalido)
{
    std::string data;
    GPSData *gpsData;
    bool esperado = false;
    bool obtenido;

    //falta un token
    data = "$GPRMC,081836,A,3751.65,S,14507.36,E,000.0,360.0,130998,011.3";
    gpsData = new GPSData(data);
    obtenido = gpsData->isValid();
    EXPECT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;
    delete gpsData;

    //tiene V
    data = "$GPRMC,081836,V,3751.65,S,14507.36,E,000.0,360.0,130998,011.3,E*62";
    gpsData = new GPSData(data);
    obtenido = gpsData->isValid();
    EXPECT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;

    delete gpsData;

    //no es GPRMC
    data = "$GPZMC,081836,A,3751.65,S,14507.36,E,000.0,360.0,130998,011.3,E*62";
    gpsData = new GPSData(data);
    obtenido = gpsData->isValid();
    EXPECT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;

    delete gpsData;
}

TEST(GPSData, getHour)
{
    std::string data = "$GPRMC,081836,A,3751.65,S,14507.36,E,000.0,360.0,130998,011.3,E*62";
    GPSData *gpsData = new GPSData(data);
    int esperado;
    int obtenido;

    esperado = 8;
    obtenido = gpsData->getDateTime().getHour();
    EXPECT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;

    delete gpsData;
}

TEST(GPSData, getMinute)
{
    std::string data = "$GPRMC,081836,A,3751.65,S,14507.36,E,000.0,360.0,130998,011.3,E*62";
    GPSData *gpsData = new GPSData(data);
    int esperado;
    int obtenido;

    esperado = 18;
    obtenido = gpsData->getDateTime().getMinute();
    EXPECT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;

    delete gpsData;
}

TEST(GPSData, getSecond)
{
    std::string data = "$GPRMC,081836,A,3751.65,S,14507.36,E,000.0,360.0,130998,011.3,E*62";
    GPSData *gpsData = new GPSData(data);
    int esperado;
    int obtenido;

    esperado = 36;
    obtenido = gpsData->getDateTime().getSecond();
    EXPECT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;

    delete gpsData;
}

TEST(GPSData, getLatitudSur)
{
    std::string data = "$GPRMC,081836,A,3751.65,S,14507.36,E,000.0,360.0,130998,011.3,E*62";
    GPSData *gpsData = new GPSData(data);
    double esperado;
    double obtenido;

    esperado = -1 * (37 + 51.65 / 60);
    obtenido = gpsData->getCoordinate().getLatitude();
    EXPECT_DOUBLE_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                         << "obtenido: " << obtenido;

    delete gpsData;
}

TEST(GPSData, getLatitudNorte)
{
    std::string data = "$GPRMC,081836,A,3751.65,N,14507.36,E,000.0,360.0,130998,011.3,E*7F";
    GPSData *gpsData = new GPSData(data);
    double esperado;
    double obtenido;

    esperado = 37 + 51.65 / 60;
    obtenido = gpsData->getCoordinate().getLatitude();
    EXPECT_DOUBLE_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                         << "obtenido: " << obtenido;

    delete gpsData;
}

TEST(GPSData, getLongitudEste)
{
    std::string data = "$GPRMC,081836,A,3751.65,N,14507.36,E,000.0,360.0,130998,011.3,E*7F";
    GPSData *gpsData = new GPSData(data);
    double esperado;
    double obtenido;

    esperado = (145 + 07.36 / 60);
    obtenido = gpsData->getCoordinate().getLongitude();
    EXPECT_DOUBLE_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                         << "obtenido: " << obtenido;

    delete gpsData;
}

TEST(GPSData, getLongitudOeste)
{
    std::string data = "$GPRMC,081836,A,3751.65,N,14507.36,W,000.0,360.0,130998,011.3,E*6D";
    GPSData *gpsData = new GPSData(data);
    double esperado;
    double obtenido;

    esperado = -1 * (145 + 07.36 / 60);
    obtenido = gpsData->getCoordinate().getLongitude();
    EXPECT_DOUBLE_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                         << "obtenido: " << obtenido;

    delete gpsData;
}

TEST(GPSData, getDay)
{
    std::string data = "$GPRMC,081836,A,3751.65,N,14507.36,W,000.0,360.0,130998,011.3,E*6D";
    GPSData *gpsData = new GPSData(data);
    int esperado;
    int obtenido;

    esperado = 13;
    obtenido = gpsData->getDateTime().getDay();
    EXPECT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;

    delete gpsData;
}

TEST(GPSData, getMonth)
{
    std::string data = "$GPRMC,081836,A,3751.65,N,14507.36,W,000.0,360.0,130998,011.3,E*6D";
    GPSData *gpsData = new GPSData(data);
    int esperado;
    int obtenido;

    esperado = 9;
    obtenido = gpsData->getDateTime().getMonth();
    EXPECT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;

    delete gpsData;
}

TEST(GPSData, getYear)
{
    std::string data = "$GPRMC,081836,A,3751.65,N,14507.36,W,000.0,360.0,130998,011.3,E*6D";
    GPSData *gpsData = new GPSData(data);
    int esperado;
    int obtenido;

    esperado = 98;
    obtenido = gpsData->getDateTime().getYear();
    EXPECT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;

    delete gpsData;
}