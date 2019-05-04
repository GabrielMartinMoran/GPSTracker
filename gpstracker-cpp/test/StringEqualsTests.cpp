#include <gtest/gtest.h>
#include <Utils/StringEquals.h>

TEST(StringEquals, equals)
{
    std::string command = "$GPRMC,081836,A,3751.65,S,14507.36,E,000.0,360.0,130998,011.3,E*62";
    EXPECT_TRUE(equals(command, command));
}