#include <gtest/gtest.h>
#include <utils/Haversine.h>

TEST(Haversine, haversine_m){
    double lat1 = 51.5007;
    double lon1 = 0.1246;
    double lat2 = 40.6892;
    double lon2 = 74.0445;
    double esperado;
    double obtenido;

    esperado = 5571340.3215750661;
    obtenido = haversine_m(&lat1, &lon1, &lat2, &lon2);
    EXPECT_DOUBLE_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;
}