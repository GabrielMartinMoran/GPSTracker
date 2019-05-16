#include <gtest/gtest.h>
#include <GPSControllerMockup.h>

TEST(GPSControllerMockup, getInformation)
{

    int pinTX = 0;
    int pinRX = 0;
    GPSControllerMockup *m1 = new GPSControllerMockup(pinTX, pinRX);
    GPSControllerMockup *m2 = new GPSControllerMockup();
    std::string command;
    
    command = "$GPRMC,081836,A,3751.65,S,14507.36,E,000.0,360.0,130998,011.3,E*62";

    EXPECT_EQ(command, m1->getInformation());
    EXPECT_EQ(command, m2->getInformation()); 

    command = "$GPRMC,054454.529,V,3654.929,N,07302.499,W,9.6,2.63,160519,,E*7F";

    EXPECT_EQ(command, m1->getInformation());
    EXPECT_EQ(command, m2->getInformation()); 

    command = "$GPGGA,054455.529,3654.929,N,07302.499,W,0,00,,,M,,M,,*5E";

    EXPECT_EQ(command, m1->getInformation());
    EXPECT_EQ(command, m2->getInformation()); 

    command = "$GPGLL,3654.929,N,07302.499,W,054456.529,V*3D";

    EXPECT_EQ(command, m1->getInformation());
    EXPECT_EQ(command, m2->getInformation()); 

    command = "$GPRMC,054457.529,A,3654.928,N,07302.500,W,41.7,2.65,160519,,E*47";

    EXPECT_EQ(command, m1->getInformation());
    EXPECT_EQ(command, m2->getInformation()); 

    command = "$GPGGA,054458.529,3654.928,N,07302.500,W,0,00,,,M,,M,,*53";

    EXPECT_EQ(command, m1->getInformation());
    EXPECT_EQ(command, m2->getInformation()); 

    command = "$GPGLL,3654.928,N,07302.500,W,054459.529,V*32";

    EXPECT_EQ(command, m1->getInformation());
    EXPECT_EQ(command, m2->getInformation()); 

    command = "$GPRMC,054500.529,A,3654.927,N,07302.502,W,75.7,2.56,160519,,E*4E";

    EXPECT_EQ(command, m1->getInformation());
    EXPECT_EQ(command, m2->getInformation()); 

    command = "$GPGGA,054501.529,3654.927,N,07302.502,W,0,00,,,M,,M,,*53";

    EXPECT_EQ(command, m1->getInformation());
    EXPECT_EQ(command, m2->getInformation()); 

    command = "$GPGLL,3654.927,N,07302.502,W,054502.529,V*30";

    EXPECT_EQ(command, m1->getInformation());
    EXPECT_EQ(command, m2->getInformation()); 

    command = "$GPRMC,054503.529,A,3654.925,N,07302.503,W,82.8,2.57,160519,,E*48";

    EXPECT_EQ(command, m1->getInformation());
    EXPECT_EQ(command, m2->getInformation()); 

    command = "$GPGGA,054504.529,3654.925,N,07302.503,W,0,00,,,M,,M,,*55";

    EXPECT_EQ(command, m1->getInformation());
    EXPECT_EQ(command, m2->getInformation()); 

    command = "$GPGLL,3654.925,N,07302.503,W,054505.529,V*34";

    EXPECT_EQ(command, m1->getInformation());
    EXPECT_EQ(command, m2->getInformation()); 

    command = "$GPRMC,054506.529,V,3654.924,N,07302.504,W,63.9,2.51,160519,,E*43";

    EXPECT_EQ(command, m1->getInformation());
    EXPECT_EQ(command, m2->getInformation()); 

    command = "$GPGGA,054507.529,3654.924,N,07302.504,W,0,00,,,M,,M,,*50";

    EXPECT_EQ(command, m1->getInformation());
    EXPECT_EQ(command, m2->getInformation()); 

    command = "$GPGLL,3654.924,N,07302.504,W,054508.529,V*3F";

    EXPECT_EQ(command, m1->getInformation());
    EXPECT_EQ(command, m2->getInformation()); 

    command = "$GPRMC,054509.529,A,3654.923,N,07302.506,W,51.1,2.54,160519,,E*45";

    EXPECT_EQ(command, m1->getInformation());
    EXPECT_EQ(command, m2->getInformation()); 

    command = "$GPGGA,054510.529,3654.923,N,07302.506,W,0,00,,,M,,M,,*53";

    EXPECT_EQ(command, m1->getInformation());
    EXPECT_EQ(command, m2->getInformation()); 

    EXPECT_FALSE(m1->hayMasSentencias());
    EXPECT_FALSE(m2->hayMasSentencias());

    EXPECT_TRUE(m1->hayMasSentencias());
    EXPECT_TRUE(m2->hayMasSentencias());

    command = "$GPRMC,081836,A,3751.65,S,14507.36,E,000.0,360.0,130998,011.3,E*62";

    EXPECT_EQ(command, m1->getInformation());
    EXPECT_EQ(command, m2->getInformation()); 

    command = "$GPRMC,054454.529,V,3654.929,N,07302.499,W,9.6,2.63,160519,,E*7F";

    EXPECT_EQ(command, m1->getInformation());
    EXPECT_EQ(command, m2->getInformation()); 

    command = "$GPGGA,054455.529,3654.929,N,07302.499,W,0,00,,,M,,M,,*5E";

    EXPECT_EQ(command, m1->getInformation());
    EXPECT_EQ(command, m2->getInformation()); 

    command = "$GPGLL,3654.929,N,07302.499,W,054456.529,V*3D";

    EXPECT_EQ(command, m1->getInformation());
    EXPECT_EQ(command, m2->getInformation()); 

    command = "$GPRMC,054457.529,A,3654.928,N,07302.500,W,41.7,2.65,160519,,E*47";

    EXPECT_EQ(command, m1->getInformation());
    EXPECT_EQ(command, m2->getInformation()); 

    command = "$GPGGA,054458.529,3654.928,N,07302.500,W,0,00,,,M,,M,,*53";

    EXPECT_EQ(command, m1->getInformation());
    EXPECT_EQ(command, m2->getInformation()); 

    command = "$GPGLL,3654.928,N,07302.500,W,054459.529,V*32";

    EXPECT_EQ(command, m1->getInformation());
    EXPECT_EQ(command, m2->getInformation()); 

    command = "$GPRMC,054500.529,A,3654.927,N,07302.502,W,75.7,2.56,160519,,E*4E";

    EXPECT_EQ(command, m1->getInformation());
    EXPECT_EQ(command, m2->getInformation()); 

    command = "$GPGGA,054501.529,3654.927,N,07302.502,W,0,00,,,M,,M,,*53";

    EXPECT_EQ(command, m1->getInformation());
    EXPECT_EQ(command, m2->getInformation()); 

    command = "$GPGLL,3654.927,N,07302.502,W,054502.529,V*30";

    EXPECT_EQ(command, m1->getInformation());
    EXPECT_EQ(command, m2->getInformation()); 

    command = "$GPRMC,054503.529,A,3654.925,N,07302.503,W,82.8,2.57,160519,,E*48";

    EXPECT_EQ(command, m1->getInformation());
    EXPECT_EQ(command, m2->getInformation()); 

    command = "$GPGGA,054504.529,3654.925,N,07302.503,W,0,00,,,M,,M,,*55";

    EXPECT_EQ(command, m1->getInformation());
    EXPECT_EQ(command, m2->getInformation()); 

    command = "$GPGLL,3654.925,N,07302.503,W,054505.529,V*34";

    EXPECT_EQ(command, m1->getInformation());
    EXPECT_EQ(command, m2->getInformation()); 

    command = "$GPRMC,054506.529,V,3654.924,N,07302.504,W,63.9,2.51,160519,,E*43";

    EXPECT_EQ(command, m1->getInformation());
    EXPECT_EQ(command, m2->getInformation()); 

    command = "$GPGGA,054507.529,3654.924,N,07302.504,W,0,00,,,M,,M,,*50";

    EXPECT_EQ(command, m1->getInformation());
    EXPECT_EQ(command, m2->getInformation()); 

    command = "$GPGLL,3654.924,N,07302.504,W,054508.529,V*3F";

    EXPECT_EQ(command, m1->getInformation());
    EXPECT_EQ(command, m2->getInformation()); 

    command = "$GPRMC,054509.529,A,3654.923,N,07302.506,W,51.1,2.54,160519,,E*45";

    EXPECT_EQ(command, m1->getInformation());
    EXPECT_EQ(command, m2->getInformation()); 

    command = "$GPGGA,054510.529,3654.923,N,07302.506,W,0,00,,,M,,M,,*53";

    EXPECT_EQ(command, m1->getInformation());
    EXPECT_EQ(command, m2->getInformation());

    delete m1;
    delete m2;
}