#include <gtest/gtest.h>
#include <GPSControllerMockup.h>

TEST(GPSControllerMockup, getInformation)
{

    int pinTX = 0;
    int pinRX = 0;
    GPSControllerMockup *m1 = new GPSControllerMockup(pinTX, pinRX);
    GPSControllerMockup *m2 = new GPSControllerMockup();
    std::string command = "$GPRMC,081836,A,3751.65,S,14507.36,E,000.0,360.0,130998,011.3,E*62";
    EXPECT_TRUE(command == m1->getInformation());
    EXPECT_TRUE(command == m2->getInformation()); 
    delete m1;
    delete m2;
}