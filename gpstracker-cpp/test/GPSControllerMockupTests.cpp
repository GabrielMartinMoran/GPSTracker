#include <gtest/gtest.h>
#include <GPSControllerMockup.h>

TEST(GPSControllerMockup, getInformation)
{

    int uartNumber = 0;
    GPSControllerMockup *m1 = new GPSControllerMockup(uartNumber);
    GPSControllerMockup *m2 = new GPSControllerMockup();
    std::string command;

    command = "$GPRMC,054457,A,3654.928,N,07302.500,W,41.7,2.65,160519,,E*40";
    EXPECT_TRUE(m1->isWaitingData());
    EXPECT_TRUE(m2->isWaitingData());

    EXPECT_EQ(command, m1->getInformation());
    EXPECT_EQ(command, m2->getInformation());

    command = "$GPRMC,054509,A,3654.923,N,07302.506,W,51.1,2.54,160519,,E*42";

    EXPECT_TRUE(m1->isWaitingData());
    EXPECT_TRUE(m2->isWaitingData());

    EXPECT_EQ(command, m1->getInformation());
    EXPECT_EQ(command, m2->getInformation());

    command = "$GPRMC,054454,V,3654.929,N,07302.499,W,009.6,02.63,160519,00000,E*7F";

    EXPECT_TRUE(m1->isWaitingData());
    EXPECT_TRUE(m2->isWaitingData());

    EXPECT_EQ(command, m1->getInformation());
    EXPECT_EQ(command, m2->getInformation());

    command = "$GPGGA,054455,3654.929,N,07302.499,W,0,00,,,M,,M,,*5E";

    EXPECT_FALSE(m1->isWaitingData());
    EXPECT_FALSE(m2->isWaitingData());

    EXPECT_TRUE(m1->isWaitingData());
    EXPECT_TRUE(m2->isWaitingData());

    EXPECT_EQ(command, m1->getInformation());
    EXPECT_EQ(command, m2->getInformation());

    command = "$GPGLL,3654,N,07302.499,W,054456.529,V*3D";

    EXPECT_TRUE(m1->isWaitingData());
    EXPECT_TRUE(m2->isWaitingData());

    EXPECT_EQ(command, m1->getInformation());
    EXPECT_EQ(command, m2->getInformation());

    command = "$GPRMC,054457,A,3654.928,N,07302.500,W,41.7,2.65,160519,,E*40";

    EXPECT_TRUE(m1->isWaitingData());
    EXPECT_TRUE(m2->isWaitingData());

    EXPECT_EQ(command, m1->getInformation());
    EXPECT_EQ(command, m2->getInformation());

    command = "$GPGGA,054458,3654.928,N,07302.500,W,0,00,,,M,,M,,*53";

    EXPECT_TRUE(m1->isWaitingData());
    EXPECT_TRUE(m2->isWaitingData());

    EXPECT_EQ(command, m1->getInformation());
    EXPECT_EQ(command, m2->getInformation());

    command = "$GPGLL,3654,N,07302.500,W,054459.529,V*32";

    EXPECT_TRUE(m1->isWaitingData());
    EXPECT_TRUE(m2->isWaitingData());

    EXPECT_EQ(command, m1->getInformation());
    EXPECT_EQ(command, m2->getInformation());

    command = "$GPRMC,054500,A,3654.907,N,07302.482,W,75.7,2.56,160519,,E*42";

    EXPECT_TRUE(m1->isWaitingData());
    EXPECT_TRUE(m2->isWaitingData());

    EXPECT_EQ(command, m1->getInformation());
    EXPECT_EQ(command, m2->getInformation());

    command = "$GPGGA,054501,3654.927,N,07302.502,W,0,00,,,M,,M,,*53";

    EXPECT_TRUE(m1->isWaitingData());
    EXPECT_TRUE(m2->isWaitingData());

    EXPECT_EQ(command, m1->getInformation());
    EXPECT_EQ(command, m2->getInformation());

    command = "$GPGLL,3654,N,07302.502,W,054502.529,V*30";

    EXPECT_TRUE(m1->isWaitingData());
    EXPECT_TRUE(m2->isWaitingData());

    EXPECT_EQ(command, m1->getInformation());
    EXPECT_EQ(command, m2->getInformation());

    command = "$GPRMC,054503,A,3654.925,N,07302.503,W,82.8,2.57,160519,,E*4F";

    EXPECT_TRUE(m1->isWaitingData());
    EXPECT_TRUE(m2->isWaitingData());

    EXPECT_EQ(command, m1->getInformation());
    EXPECT_EQ(command, m2->getInformation());

    command = "$GPGGA,054504,3654.925,N,07302.503,W,0,00,,,M,,M,,*55";

    EXPECT_TRUE(m1->isWaitingData());
    EXPECT_TRUE(m2->isWaitingData());

    EXPECT_EQ(command, m1->getInformation());
    EXPECT_EQ(command, m2->getInformation());

    command = "$GPGLL,3654,N,07302.503,W,054505.529,V*34";

    EXPECT_TRUE(m1->isWaitingData());
    EXPECT_TRUE(m2->isWaitingData());

    EXPECT_EQ(command, m1->getInformation());
    EXPECT_EQ(command, m2->getInformation());

    command = "$GPRMC,054506,V,3654.924,N,07302.504,W,63.9,2.51,160519,,E*43";

    EXPECT_TRUE(m1->isWaitingData());
    EXPECT_TRUE(m2->isWaitingData());

    EXPECT_EQ(command, m1->getInformation());
    EXPECT_EQ(command, m2->getInformation());

    command = "$GPGGA,054507,3654.924,N,07302.504,W,0,00,,,M,,M,,*50";

    EXPECT_FALSE(m1->isWaitingData());
    EXPECT_FALSE(m2->isWaitingData());

    EXPECT_TRUE(m1->isWaitingData());
    EXPECT_TRUE(m2->isWaitingData());

    EXPECT_EQ(command, m1->getInformation());
    EXPECT_EQ(command, m2->getInformation());

    command = "$GPGLL,3654,N,07302.504,W,054508.529,V*3F";

    EXPECT_TRUE(m1->isWaitingData());
    EXPECT_TRUE(m2->isWaitingData());

    EXPECT_EQ(command, m1->getInformation());
    EXPECT_EQ(command, m2->getInformation());

    command = "$GPRMC,054509,A,3654.923,N,07302.506,W,51.1,2.54,160519,,E*42";

    EXPECT_TRUE(m1->isWaitingData());
    EXPECT_TRUE(m2->isWaitingData());

    EXPECT_EQ(command, m1->getInformation());
    EXPECT_EQ(command, m2->getInformation());

    command = "$GPGGA,054510,3654.923,N,07302.506,W,0,00,,,M,,M,,*53";

    EXPECT_TRUE(m1->isWaitingData());
    EXPECT_TRUE(m2->isWaitingData());

    EXPECT_EQ(command, m1->getInformation());
    EXPECT_EQ(command, m2->getInformation());

    EXPECT_FALSE(m1->isWaitingData());
    EXPECT_FALSE(m2->isWaitingData());

    EXPECT_TRUE(m1->isWaitingData());
    EXPECT_TRUE(m2->isWaitingData());

    command = "$GPRMC,054457,A,3654.928,N,07302.500,W,41.7,2.65,160519,,E*40";

    EXPECT_EQ(command, m1->getInformation());
    EXPECT_EQ(command, m2->getInformation());

    command = "$GPRMC,054509,A,3654.923,N,07302.506,W,51.1,2.54,160519,,E*42";

    EXPECT_EQ(command, m1->getInformation());
    EXPECT_EQ(command, m2->getInformation());

    command = "$GPRMC,054454,V,3654.929,N,07302.499,W,009.6,02.63,160519,00000,E*7F";

    EXPECT_EQ(command, m1->getInformation());
    EXPECT_EQ(command, m2->getInformation());

    command = "$GPGGA,054455,3654.929,N,07302.499,W,0,00,,,M,,M,,*5E";

    EXPECT_FALSE(m1->isWaitingData());
    EXPECT_FALSE(m2->isWaitingData());

    EXPECT_TRUE(m1->isWaitingData());
    EXPECT_TRUE(m2->isWaitingData());

    EXPECT_EQ(command, m1->getInformation());
    EXPECT_EQ(command, m2->getInformation());

    delete m1;
    delete m2;
}