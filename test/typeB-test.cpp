#include <TypeConversion.h>
#include <catch2/catch.hpp>

constexpr double EPSILON = 0.1;

TEST_CASE("TypeB - Name test") { CHECK("TypeB" == TypeB::name); }

TEST_CASE("TypeB - Positive Voltage To Temperature = 0.5mV")
{
    const auto voltage = 0.5;
    REQUIRE(Approx(321.9).epsilon(EPSILON) == calculate<Conversion::Temperature, TypeB>(voltage));
}

TEST_CASE("TypeB - Positive Voltage To Temperature = 2.2mV")
{
    const auto voltage = 2.2;
    REQUIRE(Approx(665.4).epsilon(EPSILON) == calculate<Conversion::Temperature, TypeB>(voltage));
}

TEST_CASE("TypeB - Positive Temperature To Voltage = 321.9°C")
{
    const auto temperature = 321.9;
    REQUIRE(Approx(0.5).epsilon(EPSILON) == calculate<Conversion::Voltage, TypeB>(temperature));
}

TEST_CASE("TypeB - Positive Temperature To Voltage = 665.4°C")
{
    const auto temperature = 665.4;
    REQUIRE(Approx(2.2).epsilon(EPSILON) == calculate<Conversion::Voltage, TypeB>(temperature));
}