#include <TypeConversion.h>
#include <catch2/catch.hpp>

constexpr double EPSILON = 0.1;

TEST_CASE("TypeS - Positive Voltage To Temperature = 4.096mV")
{
    const auto voltage = 4.096;
    REQUIRE(Approx(486.1).epsilon(EPSILON) == calculate<Conversion::Temperature, TypeS>(voltage));
}

TEST_CASE("TypeS - Positive Voltage To Temperature = 10.0mV")
{
    const auto voltage = 10.0;
    REQUIRE(Approx(1035.6).epsilon(EPSILON) == calculate<Conversion::Temperature, TypeS>(voltage));
}

TEST_CASE("TypeS - Negative Voltage To Temperature = -0.2mV")
{
    const auto voltage = -0.2;
    REQUIRE(Approx(-41.3).epsilon(EPSILON) == calculate<Conversion::Temperature, TypeS>(voltage));
}

TEST_CASE("TypeS - Negative Voltage To Temperature = -0.1mV")
{
    const auto voltage = -0.1;
    REQUIRE(Approx(-19.4).epsilon(EPSILON) == calculate<Conversion::Temperature, TypeS>(voltage));
}

TEST_CASE("TypeS - Positive Temperature To Voltage = 1204.11°C")
{
    const auto voltage = 1204.11;
    REQUIRE(Approx(12.0).epsilon(EPSILON) == calculate<Conversion::Voltage, TypeS>(voltage));
}

TEST_CASE("TypeS - Positive Temperature To Voltage = 1451.796°C")
{
    const auto voltage = 1451.796;
    REQUIRE(Approx(15.0).epsilon(EPSILON) == calculate<Conversion::Voltage, TypeS>(voltage));
}