#include <gtest/gtest.h>
#include <GPSData.h>

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
    obtenido = gpsData->getHora();
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
    obtenido = gpsData->getMinuto();
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
    obtenido = gpsData->getSegundo();
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

    esperado = -3751.65;
    obtenido = gpsData->getLatitud();
    EXPECT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;
    
    delete gpsData;
}

TEST(GPSData, getLatitudNorte)
{
    std::string data = "$GPRMC,081836,A,3751.65,N,14507.36,E,000.0,360.0,130998,011.3,E*62";
    GPSData *gpsData = new GPSData(data);
    double esperado;
    double obtenido;

    esperado = 3751.65;
    obtenido = gpsData->getLatitud();
    EXPECT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;
    
    delete gpsData;
}

TEST(GPSData, getLongitudEste)
{
    std::string data = "$GPRMC,081836,A,3751.65,N,14507.36,E,000.0,360.0,130998,011.3,E*62";
    GPSData *gpsData = new GPSData(data);
    double esperado;
    double obtenido;

    esperado = -14507.36;
    obtenido = gpsData->getLongitud();
    EXPECT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;
    
    delete gpsData;
}

TEST(GPSData, getLongitudOeste)
{
    std::string data = "$GPRMC,081836,A,3751.65,N,14507.36,W,000.0,360.0,130998,011.3,E*62";
    GPSData *gpsData = new GPSData(data);
    double esperado;
    double obtenido;

    esperado = 14507.36;
    obtenido = gpsData->getLongitud();
    EXPECT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
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
    obtenido = gpsData->getDia();
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
    obtenido = gpsData->getMes();
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
    obtenido = gpsData->getAnio();
    EXPECT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;
    
    delete gpsData;
}