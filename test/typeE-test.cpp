#include <TypeConversion.h>
#include <catch2/catch_all.hpp>

using namespace UnitLiterals;
constexpr double EPSILON = 0.1;
using ThermocoupleType = TypeE;

TEST_CASE("TypeE - Name test")
{
    CHECK("TypeE" == ThermocoupleType::NAME);
}

TEST_CASE("TypeE - Positive Voltage To Temperature = 4.096mV")
{
    constexpr auto VOLTAGE = 4.096_mV;
    constexpr auto RESULT = Thermocouple::calculate<ThermocoupleType>(VOLTAGE);
    REQUIRE_THAT(RESULT, Catch::Matchers::WithinRel(66.4, EPSILON));
}

TEST_CASE("TypeE - Positive Voltage To Temperature = 10.0mV")
{
    constexpr auto VOLTAGE = 10.0_mV;
    constexpr auto RESULT = Thermocouple::calculate<ThermocoupleType>(VOLTAGE);
    REQUIRE_THAT(RESULT, Catch::Matchers::WithinRel(152.9, EPSILON));
}

TEST_CASE("TypeE - Negative Voltage To Temperature = -1.0mV")
{
    constexpr auto VOLTAGE = Voltage{ -1.0 };
    constexpr auto RESULT = Thermocouple::calculate<ThermocoupleType>(VOLTAGE);
    REQUIRE_THAT(RESULT, Catch::Matchers::WithinRel(-17.3, EPSILON));
}

TEST_CASE("TypeE - Negative Voltage To Temperature = -4.096mV")
{
    constexpr auto VOLTAGE = Voltage{ -4.096 };
    constexpr auto RESULT = Thermocouple::calculate<ThermocoupleType>(VOLTAGE);
    REQUIRE_THAT(RESULT, Catch::Matchers::WithinRel(-75.766, EPSILON));
}

TEST_CASE("TypeE - Positive Temperature To Voltage = 66.4Degrees")
{
    constexpr auto TEMPERATURE = 66.4_Temp;
    constexpr auto RESULT = Thermocouple::calculate<ThermocoupleType>(TEMPERATURE);
    REQUIRE_THAT(RESULT, Catch::Matchers::WithinRel(4.096, EPSILON));
}

TEST_CASE("TypeE - Positive Temperature To Voltage = 152.9Degrees")
{
    constexpr auto TEMPERATURE = 152.9_Temp;
    constexpr auto RESULT = Thermocouple::calculate<ThermocoupleType>(TEMPERATURE);
    REQUIRE_THAT(RESULT, Catch::Matchers::WithinRel(10.0, EPSILON));
}

TEST_CASE("TypeE - Negative Temperature To Voltage = -17.3Degrees")
{
    constexpr auto TEMPERATURE = Temperature{ -17.3 };
    constexpr auto RESULT = Thermocouple::calculate<ThermocoupleType>(TEMPERATURE);
    REQUIRE_THAT(RESULT, Catch::Matchers::WithinRel(-1.0, EPSILON));
}

TEST_CASE("TypeE - Negative Temperature To Voltage = -75.766Degrees")
{
    constexpr auto TEMPERATURE = Temperature{ -75.766 };
    constexpr auto RESULT = Thermocouple::calculate<ThermocoupleType>(TEMPERATURE);
    REQUIRE_THAT(RESULT, Catch::Matchers::WithinRel(-4.096, EPSILON));
}
