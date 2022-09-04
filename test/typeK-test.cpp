#define CATCH_CONFIG_MAIN
#include <TypeConversion.h>
#include <catch2/catch.hpp>

constexpr double EPSILON = 0.1;

TEST_CASE("TypeK - Name test") { CHECK("TypeK" == TypeK::NAME); }

TEST_CASE("TypeK - Positive Voltage To Temperature = 4.096mV")
{
    const auto VOLTAGE = 4.096;
    REQUIRE(Approx(100.0).epsilon(EPSILON) == calculate<Conversion::Temperature, TypeK>(VOLTAGE));
}

TEST_CASE("TypeK - Positive Voltage To Temperature = 10.0mV")
{
    const auto VOLTAGE = 10.0;
    REQUIRE(Approx(246.2).epsilon(EPSILON) == calculate<Conversion::Temperature, TypeK>(VOLTAGE));
}

TEST_CASE("TypeK - Negative Voltage To Temperature = -1.0mV")
{
    const auto VOLTAGE = -1.0;
    REQUIRE(Approx(-25.8).epsilon(EPSILON) == calculate<Conversion::Temperature, TypeK>(VOLTAGE));
}

TEST_CASE("TypeK - Negative Voltage To Temperature = -4.096mV")
{
    const auto VOLTAGE = -4.096;
    REQUIRE(Approx(-118.5).epsilon(EPSILON) == calculate<Conversion::Temperature, TypeK>(VOLTAGE));
}

TEST_CASE("TypeK - Positive Temperature To Voltage = 100.0°C")
{
    const auto VOLTAGE = 100.0;
    REQUIRE(Approx(4.096).epsilon(EPSILON) == calculate<Conversion::Voltage, TypeK>(VOLTAGE));
}

TEST_CASE("TypeK - Positive Temperature To Voltage = 246.2°C")
{
    const auto VOLTAGE = 246.2;
    REQUIRE(Approx(10.0).epsilon(EPSILON) == calculate<Conversion::Voltage, TypeK>(VOLTAGE));
}

TEST_CASE("TypeK - Positive Temperature To Voltage = -25.8°C")
{
    const auto VOLTAGE = -25.8;
    REQUIRE(Approx(-1.0).epsilon(EPSILON) == calculate<Conversion::Voltage, TypeK>(VOLTAGE));
}

TEST_CASE("TypeK - Positive Temperature To Voltage = -118.5°C")
{
    const auto VOLTAGE = -118.5;
    REQUIRE(Approx(-4.096).epsilon(EPSILON) == calculate<Conversion::Voltage, TypeK>(VOLTAGE));
}
