#define CATCH_CONFIG_MAIN
#include <TypeConversion.h>
#include <catch2/catch_all.hpp>

using namespace UnitLiterals;
constexpr double EPSILON = 0.1;
using ThermocoupleType = TypeK;

TEST_CASE("TypeK - Name test")
{
    CHECK("TypeK" == ThermocoupleType::NAME);
}

TEST_CASE("TypeK - Positive Voltage To Temperature = 4.096mV")
{
    constexpr auto VOLTAGE = 4.096_mV;
    constexpr auto RESULT = Thermocouple::calculate<ThermocoupleType>(VOLTAGE);
    REQUIRE_THAT(RESULT, Catch::Matchers::WithinRel(100.0, EPSILON));
}

TEST_CASE("TypeK - Positive Voltage To Temperature = 10.0mV")
{
    constexpr auto VOLTAGE = 10.0_mV;
    constexpr auto RESULT = Thermocouple::calculate<ThermocoupleType>(VOLTAGE);
    REQUIRE_THAT(RESULT, Catch::Matchers::WithinRel(246.2, EPSILON));
}

TEST_CASE("TypeK - Negative Voltage To Temperature = -1.0mV")
{
    constexpr auto VOLTAGE = Voltage{ -1.0 };
    constexpr auto RESULT = Thermocouple::calculate<ThermocoupleType>(VOLTAGE);
    REQUIRE_THAT(RESULT, Catch::Matchers::WithinRel(-25.8, EPSILON));
}

TEST_CASE("TypeK - Negative Voltage To Temperature = -4.096mV")
{
    constexpr auto VOLTAGE = Voltage{ -4.096 };
    constexpr auto RESULT = Thermocouple::calculate<ThermocoupleType>(VOLTAGE);
    REQUIRE_THAT(RESULT, Catch::Matchers::WithinRel(-118.5, EPSILON));
}

TEST_CASE("TypeK - Positive Temperature To Voltage = 100.0Degrees")
{
    constexpr auto TEMP = 100.0_Temp;
    constexpr auto RESULT = Thermocouple::calculate<ThermocoupleType>(TEMP);
    REQUIRE_THAT(RESULT, Catch::Matchers::WithinRel(4.096, EPSILON));
}

TEST_CASE("TypeK - Positive Temperature To Voltage = 246.2Degrees")
{
    constexpr auto TEMP = 246.2_Temp;
    constexpr auto RESULT = Thermocouple::calculate<ThermocoupleType>(TEMP);
    REQUIRE_THAT(RESULT, Catch::Matchers::WithinRel(10.0, EPSILON));
}

TEST_CASE("TypeK - Positive Temperature To Voltage = -25.8Degrees")
{
    constexpr auto TEMP = Temperature{ -25.8 };
    constexpr auto RESULT = Thermocouple::calculate<ThermocoupleType>(TEMP);
    REQUIRE_THAT(RESULT, Catch::Matchers::WithinRel(-1.0, EPSILON));
}

TEST_CASE("TypeK - Positive Temperature To Voltage = -118.5Degrees")
{
    constexpr auto TEMP = Temperature{ -118.5 };
    constexpr auto RESULT = Thermocouple::calculate<ThermocoupleType>(TEMP);
    REQUIRE_THAT(RESULT, Catch::Matchers::WithinRel(-4.096, EPSILON));
}
