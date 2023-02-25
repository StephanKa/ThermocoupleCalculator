#include <TypeConversion.h>
#include <catch2/catch_all.hpp>

using namespace UnitLiterals;
constexpr double EPSILON = 0.1;
using ThermocoupleType = TypeT;

TEST_CASE("TypeT - Name test") { CHECK("TypeT" == TypeT::NAME); }

TEST_CASE("TypeT - Positive Voltage To Temperature = 4.096mV")
{
    constexpr auto VOLTAGE = 4.096_mV;
    constexpr auto RESULT = Thermocouple::calculate<ThermocoupleType>(VOLTAGE);
    REQUIRE_THAT(RESULT, Catch::Matchers::WithinRel(96.1, EPSILON));
}

TEST_CASE("TypeT - Positive Voltage To Temperature = 10.0mV")
{
    constexpr auto VOLTAGE = 10.0_mV;
    constexpr auto RESULT = Thermocouple::calculate<ThermocoupleType>(VOLTAGE);
    REQUIRE_THAT(RESULT, Catch::Matchers::WithinRel(213.3, EPSILON));
}

TEST_CASE("TypeT - Negative Voltage To Temperature = -1.0mV")
{
    constexpr auto VOLTAGE = Voltage{-1.0};
    constexpr auto RESULT = Thermocouple::calculate<ThermocoupleType>(VOLTAGE);
    REQUIRE_THAT(RESULT, Catch::Matchers::WithinRel(-26.6, EPSILON));
}

TEST_CASE("TypeT - Negative Voltage To Temperature = -3.9mV")
{
    constexpr auto VOLTAGE = Voltage{-3.9};
    constexpr auto RESULT = Thermocouple::calculate<ThermocoupleType>(VOLTAGE);
    REQUIRE_THAT(RESULT, Catch::Matchers::WithinRel(-119.1, EPSILON));
}

TEST_CASE("TypeT - Positive Temperature To Voltage = 249.76Degrees")
{
    constexpr auto TEMP = 249.76_Temp;
    constexpr auto RESULT = Thermocouple::calculate<ThermocoupleType>(TEMP);
    REQUIRE_THAT(RESULT, Catch::Matchers::WithinRel(12.0, EPSILON));
}

TEST_CASE("TypeT - Positive Temperature To Voltage = 302.375Degrees")
{
    constexpr auto TEMP = 302.375_Temp;
    constexpr auto RESULT = Thermocouple::calculate<ThermocoupleType>(TEMP);
    REQUIRE_THAT(RESULT, Catch::Matchers::WithinRel(15.0, EPSILON));
}

TEST_CASE("TypeT - Positive Temperature To Voltage = -87.008Degrees")
{
    constexpr auto TEMP = Temperature{-87.008};
    constexpr auto RESULT = Thermocouple::calculate<ThermocoupleType>(TEMP);
    REQUIRE_THAT(RESULT, Catch::Matchers::WithinRel(-3.0, EPSILON));
}

TEST_CASE("TypeT - Positive Temperature To Voltage = -26.649Degrees")
{
    constexpr auto TEMP = Temperature{-26.649};
    constexpr auto RESULT = Thermocouple::calculate<ThermocoupleType>(TEMP);
    REQUIRE_THAT(RESULT, Catch::Matchers::WithinRel(-1, EPSILON));
}
