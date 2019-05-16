#include <gtest/gtest.h>
#include <utils/StringToNumber.h>

TEST(StringToNumber, stringToNumberInt){
    int esperado;
    int obtenido;

    esperado = 8;
    obtenido = stringToNumber<int>("8");
    ASSERT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;
    
    esperado = 24;
    obtenido = stringToNumber<int>("24");
    ASSERT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;
    
    esperado = 0;
    obtenido = stringToNumber<int>("");
    ASSERT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;
    
    esperado = -1;
    obtenido = stringToNumber<int>("-1");
    ASSERT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;
    
    esperado = -3451;
    obtenido = stringToNumber<int>("-3451");
    ASSERT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;
}

TEST(StringToNumber, stringToNumberDouble){
    double esperado;
    double obtenido;

    esperado = 8;
    obtenido = stringToNumber<double>("8");
    ASSERT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;
    
    esperado = 24.8;
    obtenido = stringToNumber<double>("24.8");
    ASSERT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;
    
    esperado = 0;
    obtenido = stringToNumber<double>("");
    ASSERT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;
    
    esperado = -1;
    obtenido = stringToNumber<double>("-1");
    ASSERT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;
    
    esperado = -3451.345;
    obtenido = stringToNumber<double>("-3451.345");
    ASSERT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;
}

TEST(StringToNumber, stringToNumberFloat){
    float esperado;
    float obtenido;

    esperado = 8;
    obtenido = stringToNumber<float>("8");
    ASSERT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;
    
    esperado = 24.8;
    obtenido = stringToNumber<float>("24.8");
    ASSERT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;
    
    esperado = 0;
    obtenido = stringToNumber<float>("");
    ASSERT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;
    
    esperado = -1;
    obtenido = stringToNumber<float>("-1");
    ASSERT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;
    
    esperado = -3451.345;
    obtenido = stringToNumber<float>("-3451.345");
    ASSERT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;
}