#include <TypeConversion.h>
#include <catch2/catch_test_macros.hpp>

using namespace UnitLiterals;
constexpr double EPSILON = 0.1;

TEST_CASE("TypeJ - Name test") { CHECK("TypeJ" == TypeJ::NAME); }

TEST_CASE("TypeJ - Positive Voltage To Temperature = 4.096mV")
{
    const auto VOLTAGE = 4.096_mV;
    REQUIRE(Approx(78.3).epsilon(EPSILON) == Thermocouple::calculate<TypeJ>(VOLTAGE));
}

TEST_CASE("TypeJ - Positive Voltage To Temperature = 10.0mV")
{
    const auto VOLTAGE = 10.0_mV;
    REQUIRE(Approx(185.9).epsilon(EPSILON) == Thermocouple::calculate<TypeJ>(VOLTAGE));
}

TEST_CASE("TypeJ - Negative Voltage To Temperature = -1.0mV")
{
    const auto VOLTAGE = Voltage{-1.0};
    REQUIRE(Approx(-20.1).epsilon(EPSILON) == Thermocouple::calculate<TypeJ>(VOLTAGE));
}

TEST_CASE("TypeJ - Negative Voltage To Temperature = -4.096mV")
{
    const auto VOLTAGE = Voltage{-4.096};
    REQUIRE(Approx(-87.2).epsilon(EPSILON) == Thermocouple::calculate<TypeJ>(VOLTAGE));
}

TEST_CASE("TypeJ - Positive Temperature To Voltage = 221.994°C")
{
    const auto TEMP = 221.994_Temp;
    REQUIRE(Approx(12.0).epsilon(EPSILON) == Thermocouple::calculate<TypeJ>(TEMP));
}

TEST_CASE("TypeJ - Positive Temperature To Voltage = 276.043°C")
{
    const auto TEMP = 276.043_Temp;
    REQUIRE(Approx(15.0).epsilon(EPSILON) == Thermocouple::calculate<TypeJ>(TEMP));
}

TEST_CASE("TypeJ - Positive Temperature To Voltage = -62.353°C")
{
    const auto TEMP = Temperature{-62.353};
    REQUIRE(Approx(-3.0).epsilon(EPSILON) == Thermocouple::calculate<TypeJ>(TEMP));
}

TEST_CASE("TypeJ - Positive Temperature To Voltage = -109.079°C")
{
    const auto TEMP = Temperature{-109.079};
    REQUIRE(Approx(-5).epsilon(EPSILON) == Thermocouple::calculate<TypeJ>(TEMP));
}
