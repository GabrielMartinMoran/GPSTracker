#include <gtest/gtest.h>
#include <utils/StringTokenizer.h>

TEST(StringTokenizer, tokens)
{
    std::string command = "$GPRMC,081836,A,3751.65,S,14507.36,E,000.0,360.0,130998,011.3,E*62";
    StringTokenizer tokens(command, ",");
    std::string esperado = "$GPRMC";
    std::string obtenido = tokens.nextToken();
    EXPECT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;
    esperado = "081836";
    obtenido = tokens.nextToken();
    EXPECT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;
    esperado = "A";
    obtenido = tokens.nextToken();
    EXPECT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;
    esperado = "3751.65";
    obtenido = tokens.nextToken();
    EXPECT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;
    esperado = "S";
    obtenido = tokens.nextToken();
    EXPECT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;
    esperado = "14507.36";
    obtenido = tokens.nextToken();
    EXPECT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;
    esperado = "E";
    obtenido = tokens.nextToken();
    EXPECT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;
    esperado = "000.0";
    obtenido = tokens.nextToken();
    EXPECT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;
    esperado = "360.0";
    obtenido = tokens.nextToken();
    EXPECT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;
    esperado = "130998";
    obtenido = tokens.nextToken();
    EXPECT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;
    esperado = "011.3";
    obtenido = tokens.nextToken();
    EXPECT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;
    esperado = "E*62";
    obtenido = tokens.nextToken();
    EXPECT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;
    
}

TEST(StringTokenizer, NoMoreTokensException)
{
    StringTokenizer tokens("", ",");
    EXPECT_THROW(tokens.nextToken(), NoMoreTokensException);
}