#include <TypeConversion.h>
#include <catch2/catch_all.hpp>

using namespace UnitLiterals;
constexpr double EPSILON = 0.1;

TEST_CASE("TypeE - Name test") { CHECK("TypeE" == TypeE::NAME); }

TEST_CASE("TypeE - Positive Voltage To Temperature = 4.096mV")
{
    const auto VOLTAGE = 4.096_mV;
    REQUIRE_THAT(Thermocouple::calculate<TypeE>(VOLTAGE), Catch::Matchers::WithinRel(66.4, EPSILON));
}

TEST_CASE("TypeE - Positive Voltage To Temperature = 10.0mV")
{
    const auto VOLTAGE = 10.0_mV;
    REQUIRE_THAT(Thermocouple::calculate<TypeE>(VOLTAGE), Catch::Matchers::WithinRel(152.9, EPSILON));
}

TEST_CASE("TypeE - Negative Voltage To Temperature = -1.0mV")
{
    const auto VOLTAGE = Voltage{-1.0};
    REQUIRE_THAT(Thermocouple::calculate<TypeE>(VOLTAGE), Catch::Matchers::WithinRel(-17.3, EPSILON));
}

TEST_CASE("TypeE - Negative Voltage To Temperature = -4.096mV")
{
    const auto VOLTAGE = Voltage{-4.096};
    REQUIRE_THAT(Thermocouple::calculate<TypeE>(VOLTAGE), Catch::Matchers::WithinRel(-75.766, EPSILON));
}

TEST_CASE("TypeE - Positive Temperature To Voltage = 66.4°C")
{
    const auto TEMPERATURE = 66.4_Temp;
    REQUIRE_THAT(Thermocouple::calculate<TypeE>(TEMPERATURE), Catch::Matchers::WithinRel(4.096, EPSILON));
}

TEST_CASE("TypeE - Positive Temperature To Voltage = 152.9°C")
{
    const auto TEMPERATURE = 152.9_Temp;
    REQUIRE_THAT(Thermocouple::calculate<TypeE>(TEMPERATURE), Catch::Matchers::WithinRel(10.0, EPSILON));
}

TEST_CASE("TypeE - Negative Temperature To Voltage = -17.3°C")
{
    const auto TEMPERATURE = Temperature{-17.3};
    REQUIRE_THAT(Thermocouple::calculate<TypeE>(TEMPERATURE), Catch::Matchers::WithinRel(-1.0, EPSILON));
}

TEST_CASE("TypeE - Negative Temperature To Voltage = -75.766°C")
{
    const auto TEMPERATURE = Temperature{-75.766};
    REQUIRE_THAT(Thermocouple::calculate<TypeE>(TEMPERATURE), Catch::Matchers::WithinRel(-4.096, EPSILON));
}
