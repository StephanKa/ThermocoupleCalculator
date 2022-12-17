#define CATCH_CONFIG_MAIN
#include <TypeConversion.h>
#include <catch2/catch_test_macros.hpp>

using namespace UnitLiterals;
constexpr double EPSILON = 0.1;

TEST_CASE("TypeK - Name test") { CHECK("TypeK" == TypeK::NAME); }

TEST_CASE("TypeK - Positive Voltage To Temperature = 4.096mV")
{
    const auto VOLTAGE = 4.096_mV;
    REQUIRE(Approx(100.0).epsilon(EPSILON) == Thermocouple::calculate<TypeK>(VOLTAGE));
}

TEST_CASE("TypeK - Positive Voltage To Temperature = 10.0mV")
{
    const auto VOLTAGE = 10.0_mV;
    REQUIRE(Approx(246.2).epsilon(EPSILON) == Thermocouple::calculate<TypeK>(VOLTAGE));
}

TEST_CASE("TypeK - Negative Voltage To Temperature = -1.0mV")
{
    const auto VOLTAGE = Voltage{-1.0};
    REQUIRE(Approx(-25.8).epsilon(EPSILON) == Thermocouple::calculate<TypeK>(VOLTAGE));
}

TEST_CASE("TypeK - Negative Voltage To Temperature = -4.096mV")
{
    const auto VOLTAGE = Voltage{-4.096};
    REQUIRE(Approx(-118.5).epsilon(EPSILON) == Thermocouple::calculate<TypeK>(VOLTAGE));
}

TEST_CASE("TypeK - Positive Temperature To Voltage = 100.0°C")
{
    const auto TEMP = 100.0_Temp;
    REQUIRE(Approx(4.096).epsilon(EPSILON) == Thermocouple::calculate<TypeK>(TEMP));
}

TEST_CASE("TypeK - Positive Temperature To Voltage = 246.2°C")
{
    const auto TEMP = 246.2_Temp;
    REQUIRE(Approx(10.0).epsilon(EPSILON) == Thermocouple::calculate<TypeK>(TEMP));
}

TEST_CASE("TypeK - Positive Temperature To Voltage = -25.8°C")
{
    const auto TEMP = Temperature{-25.8};
    REQUIRE(Approx(-1.0).epsilon(EPSILON) == Thermocouple::calculate<TypeK>(TEMP));
}

TEST_CASE("TypeK - Positive Temperature To Voltage = -118.5°C")
{
    const auto TEMP = Temperature{-118.5};
    REQUIRE(Approx(-4.096).epsilon(EPSILON) == Thermocouple::calculate<TypeK>(TEMP));
}
