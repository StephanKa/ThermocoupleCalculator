#include <TypeConversion.h>
#include <catch2/catch.hpp>

constexpr double EPSILON = 0.1;
TEST_CASE("TypeJ - Positive Voltage To Temperature = 4.096mV")
{
    const auto voltage = 4.096;
    REQUIRE(Approx(78.3).epsilon(EPSILON) == calculate<TypeJ, Conversion::Temperature>(voltage));
}

TEST_CASE("TypeJ - Positive Voltage To Temperature = 10.0mV")
{
    const auto voltage = 10.0;
    REQUIRE(Approx(185.9).epsilon(EPSILON) == calculate<TypeJ, Conversion::Temperature>(voltage));
}

TEST_CASE("TypeJ - Negative Voltage To Temperature = -1.0mV")
{
    const auto voltage = -1.0;
    REQUIRE(Approx(-20.1).epsilon(EPSILON) == calculate<TypeJ, Conversion::Temperature>(voltage));
}

TEST_CASE("TypeJ - Negative Voltage To Temperature = -4.096mV")
{
    const auto voltage = -4.096;
    REQUIRE(Approx(-87.2).epsilon(EPSILON) == calculate<TypeJ, Conversion::Temperature>(voltage));
}

TEST_CASE("TypeJ - Positive Temperature To Voltage = 221.994°C")
{
    const auto voltage = 221.994;
    REQUIRE(Approx(12.0).epsilon(EPSILON) == calculate<TypeJ, Conversion::Voltage>(voltage));
}

TEST_CASE("TypeJ - Positive Temperature To Voltage = 276.043°C")
{
    const auto voltage = 276.043;
    REQUIRE(Approx(15.0).epsilon(EPSILON) == calculate<TypeJ, Conversion::Voltage>(voltage));
}

TEST_CASE("TypeJ - Positive Temperature To Voltage = -62.353°C")
{
    const auto voltage = -62.353;
    REQUIRE(Approx(-3.0).epsilon(EPSILON) == calculate<TypeJ, Conversion::Voltage>(voltage));
}

TEST_CASE("TypeJ - Positive Temperature To Voltage = -109.079°C")
{
    const auto voltage = -109.079;
    REQUIRE(Approx(-5).epsilon(EPSILON) == calculate<TypeJ, Conversion::Voltage>(voltage));
}