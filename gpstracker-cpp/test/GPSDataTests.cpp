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