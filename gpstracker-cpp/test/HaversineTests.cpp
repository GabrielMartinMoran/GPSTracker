#include <gtest/gtest.h>
#include <utils/Haversine.h>

TEST(Haversine, haversine_m){
    float lat1 = 51.5007;
    float lon1 = 0.1246;
    float lat2 = 40.6892;
    float lon2 = 74.0445;
    double esperado;
    double obtenido;

    esperado = 5571340.3088837052;
    obtenido = haversine_m(lat1, lon1, lat2, lon2);
    ASSERT_EQ(esperado, obtenido) << "esperado: " << esperado << "\n"
                                  << "obtenido: " << obtenido;
}