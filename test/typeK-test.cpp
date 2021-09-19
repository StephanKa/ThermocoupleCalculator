#define CATCH_CONFIG_MAIN
#include <TypeConversion.h>
#include <catch2/catch.hpp>

constexpr double EPSILON = 0.1;

TEST_CASE("TypeK - Positive Voltage To Temperature = 4.096mV")
{
    const auto voltage = 4.096;
    REQUIRE(Approx(100.0).epsilon(EPSILON) == calculate<Conversion::Temperature, TypeK>(voltage));
}

TEST_CASE("TypeK - Positive Voltage To Temperature = 10.0mV")
{
    const auto voltage = 10.0;
    REQUIRE(Approx(246.2).epsilon(EPSILON) == calculate<Conversion::Temperature, TypeK>(voltage));
}

TEST_CASE("TypeK - Negative Voltage To Temperature = -1.0mV")
{
    const auto voltage = -1.0;
    REQUIRE(Approx(-25.8).epsilon(EPSILON) == calculate<Conversion::Temperature, TypeK>(voltage));
}

TEST_CASE("TypeK - Negative Voltage To Temperature = -4.096mV")
{
    const auto voltage = -4.096;
    REQUIRE(Approx(-118.5).epsilon(EPSILON) == calculate<Conversion::Temperature, TypeK>(voltage));
}

TEST_CASE("TypeK - Positive Temperature To Voltage = 100.0°C")
{
    const auto voltage = 100.0;
    REQUIRE(Approx(4.096).epsilon(EPSILON) == calculate<Conversion::Voltage, TypeK>(voltage));
}

TEST_CASE("TypeK - Positive Temperature To Voltage = 246.2°C")
{
    const auto voltage = 246.2;
    REQUIRE(Approx(10.0).epsilon(EPSILON) == calculate<Conversion::Voltage, TypeK>(voltage));
}

TEST_CASE("TypeK - Positive Temperature To Voltage = -25.8°C")
{
    const auto voltage = -25.8;
    REQUIRE(Approx(-1.0).epsilon(EPSILON) == calculate<Conversion::Voltage, TypeK>(voltage));
}

TEST_CASE("TypeK - Positive Temperature To Voltage = -118.5°C")
{
    const auto voltage = -118.5;
    REQUIRE(Approx(-4.096).epsilon(EPSILON) == calculate<Conversion::Voltage, TypeK>(voltage));
}