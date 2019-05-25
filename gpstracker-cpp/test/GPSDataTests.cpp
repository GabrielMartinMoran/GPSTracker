#include <gtest/gtest.h>
#include <GPS/GPSData.h>

TEST(GPSData, normalizedData)
{
    std::string data;
    std::string esperado;
    std::string obtenido;

    data = "$GPRMC,081836,A,3751.65,S,14507.36,E,000.0,360.0,130998,011.3,E*62";
    GPSData gpsData = GPSData(data);
    esperado = "98-09-13 08:18:36,-037.86083,-145.12267\n";
    obtenido = gpsData.getNormalizedData();
    EXPECT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;
    
    data = "$GPRMC,221315,A,3751.65,N,14507.36,W,000.0,360.0,150418,011.3,E*62";
    gpsData = GPSData(data);
    esperado = "18-04-15 22:13:15,+037.86083,+145.12267\n";
    obtenido = gpsData.getNormalizedData();
    EXPECT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;
    
    data = "$GPRMC,000000,A,3751.65,S,14507.36,W,000.0,360.0,010100,011.3,E*62";
    gpsData = GPSData(data);
    esperado = "00-01-01 00:00:00,-037.86083,+145.12267\n";
    obtenido = gpsData.getNormalizedData();
    EXPECT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;
    
    data = "$GPRMC,000000,A,3751.65,N,14507.36,E,000.0,360.0,010100,011.3,E*62";
    gpsData = GPSData(data);
    esperado = "00-01-01 00:00:00,+037.86083,-145.12267\n";
    obtenido = gpsData.getNormalizedData();
    EXPECT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;
    
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

TEST(GPSData, valido)
{
    std::string data = "$GPRMC,081836,A,3751.65,S,14507.36,E,000.0,360.0,130998,011.3,E*62";
    GPSData *gpsData = new GPSData(data);
    bool esperado = true;
    bool obtenido = gpsData->isValido();
    EXPECT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;
    delete gpsData;
}

TEST(GPSData, invalido)
{
    std::string data;
    GPSData *gpsData = new GPSData(data);
    bool esperado = false;
    bool obtenido;

    data = "$GPRMC,081836,A,3751.65,S,14507.36,E,000.0,360.0,130998,011.3";
    obtenido = gpsData->isValido();
    EXPECT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;

    data = "$GPRMC,081836,V,3751.65,S,14507.36,E,000.0,360.0,130998,011.3,E*62";
    obtenido = gpsData->isValido();
    EXPECT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;

    data = "$GPZMC,081836,A,3751.65,S,14507.36,E,000.0,360.0,130998,011.3,E*62";
    obtenido = gpsData->isValido();
    EXPECT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;

    delete gpsData;
}

TEST(GPSData, getHora)
{
    std::string data = "$GPRMC,081836,A,3751.65,S,14507.36,E,000.0,360.0,130998,011.3,E*62";
    GPSData *gpsData = new GPSData(data);
    int esperado;
    int obtenido;

    esperado = 8;
    obtenido = gpsData->dateTime().getHora();
    EXPECT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;

    delete gpsData;
}

TEST(GPSData, getMinuto)
{
    std::string data = "$GPRMC,081836,A,3751.65,S,14507.36,E,000.0,360.0,130998,011.3,E*62";
    GPSData *gpsData = new GPSData(data);
    int esperado;
    int obtenido;

    esperado = 18;
    obtenido = gpsData->dateTime().getMinuto();
    EXPECT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;

    delete gpsData;
}

TEST(GPSData, getSegundo)
{
    std::string data = "$GPRMC,081836,A,3751.65,S,14507.36,E,000.0,360.0,130998,011.3,E*62";
    GPSData *gpsData = new GPSData(data);
    int esperado;
    int obtenido;

    esperado = 36;
    obtenido = gpsData->dateTime().getSegundo();
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
    obtenido = gpsData->getCoordenada().getLatitud();
    EXPECT_DOUBLE_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                         << "obtenido: " << obtenido;

    delete gpsData;
}

TEST(GPSData, getLatitudNorte)
{
    std::string data = "$GPRMC,081836,A,3751.65,N,14507.36,E,000.0,360.0,130998,011.3,E*62";
    GPSData *gpsData = new GPSData(data);
    double esperado;
    double obtenido;

    esperado = 37 + 51.65 / 60;
    obtenido = gpsData->getCoordenada().getLatitud();
    EXPECT_DOUBLE_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                         << "obtenido: " << obtenido;

    delete gpsData;
}

TEST(GPSData, getLongitudEste)
{
    std::string data = "$GPRMC,081836,A,3751.65,N,14507.36,E,000.0,360.0,130998,011.3,E*62";
    GPSData *gpsData = new GPSData(data);
    double esperado;
    double obtenido;

    esperado = -1 * (145 + 07.36 / 60);
    obtenido = gpsData->getCoordenada().getLongitud();
    EXPECT_DOUBLE_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                         << "obtenido: " << obtenido;

    delete gpsData;
}

TEST(GPSData, getLongitudOeste)
{
    std::string data = "$GPRMC,081836,A,3751.65,N,14507.36,W,000.0,360.0,130998,011.3,E*62";
    GPSData *gpsData = new GPSData(data);
    double esperado;
    double obtenido;

    esperado = 145 + 07.36 / 60;
    obtenido = gpsData->getCoordenada().getLongitud();
    EXPECT_DOUBLE_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                         << "obtenido: " << obtenido;

    delete gpsData;
}

TEST(GPSData, getDia)
{
    std::string data = "$GPRMC,081836,A,3751.65,N,14507.36,W,000.0,360.0,130998,011.3,E*62";
    GPSData *gpsData = new GPSData(data);
    int esperado;
    int obtenido;

    esperado = 13;
    obtenido = gpsData->dateTime().getDia();
    EXPECT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;

    delete gpsData;
}

TEST(GPSData, getMes)
{
    std::string data = "$GPRMC,081836,A,3751.65,N,14507.36,W,000.0,360.0,130998,011.3,E*62";
    GPSData *gpsData = new GPSData(data);
    int esperado;
    int obtenido;

    esperado = 9;
    obtenido = gpsData->dateTime().getMes();
    EXPECT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;

    delete gpsData;
}

TEST(GPSData, getAnio)
{
    std::string data = "$GPRMC,081836,A,3751.65,N,14507.36,W,000.0,360.0,130998,011.3,E*62";
    GPSData *gpsData = new GPSData(data);
    int esperado;
    int obtenido;

    esperado = 98;
    obtenido = gpsData->dateTime().getAnio();
    EXPECT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;

    delete gpsData;
}