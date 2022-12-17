#define CATCH_CONFIG_MAIN
#include <TypeConversion.h>
#include <catch2/catch_all.hpp>

using namespace UnitLiterals;
constexpr double EPSILON = 0.1;

TEST_CASE("TypeK - Name test") { CHECK("TypeK" == TypeK::NAME); }

TEST_CASE("TypeK - Positive Voltage To Temperature = 4.096mV")
{
    const auto VOLTAGE = 4.096_mV;
    REQUIRE_THAT(Thermocouple::calculate<TypeK>(VOLTAGE), Catch::Matchers::WithinRel(100.0, EPSILON));
}

TEST_CASE("TypeK - Positive Voltage To Temperature = 10.0mV")
{
    const auto VOLTAGE = 10.0_mV;
    REQUIRE_THAT(Thermocouple::calculate<TypeK>(VOLTAGE), Catch::Matchers::WithinRel(246.2, EPSILON));
}

TEST_CASE("TypeK - Negative Voltage To Temperature = -1.0mV")
{
    const auto VOLTAGE = Voltage{-1.0};
    REQUIRE_THAT(Thermocouple::calculate<TypeK>(VOLTAGE), Catch::Matchers::WithinRel(-25.8, EPSILON));
}

TEST_CASE("TypeK - Negative Voltage To Temperature = -4.096mV")
{
    const auto VOLTAGE = Voltage{-4.096};
    REQUIRE_THAT(Thermocouple::calculate<TypeK>(VOLTAGE), Catch::Matchers::WithinRel(-118.5, EPSILON));
}

TEST_CASE("TypeK - Positive Temperature To Voltage = 100.0°C")
{
    const auto TEMP = 100.0_Temp;
    REQUIRE_THAT(Thermocouple::calculate<TypeK>(TEMP), Catch::Matchers::WithinRel(4.096, EPSILON));
}

TEST_CASE("TypeK - Positive Temperature To Voltage = 246.2°C")
{
    const auto TEMP = 246.2_Temp;
    REQUIRE_THAT(Thermocouple::calculate<TypeK>(TEMP), Catch::Matchers::WithinRel(10.0, EPSILON));
}

TEST_CASE("TypeK - Positive Temperature To Voltage = -25.8°C")
{
    const auto TEMP = Temperature{-25.8};
    REQUIRE_THAT(Thermocouple::calculate<TypeK>(TEMP), Catch::Matchers::WithinRel(-1.0, EPSILON));
}

TEST_CASE("TypeK - Positive Temperature To Voltage = -118.5°C")
{
    const auto TEMP = Temperature{-118.5};
    REQUIRE_THAT(Thermocouple::calculate<TypeK>(TEMP), Catch::Matchers::WithinRel(-4.096, EPSILON));
}
