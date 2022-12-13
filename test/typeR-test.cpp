#include <TypeConversion.h>
#include <catch2/catch.hpp>

using namespace UnitLiterals;
constexpr double EPSILON = 0.1;

TEST_CASE("TypeR - Name test") { CHECK("TypeR" == TypeR::NAME); }

TEST_CASE("TypeR - Positive Voltage To Temperature = 4.096mV")
{
    const auto VOLTAGE = 4.096_mV;
    REQUIRE(Approx(465.2).epsilon(EPSILON) == Thermocouple::calculate<TypeR>(VOLTAGE));
}

TEST_CASE("TypeR - Positive Voltage To Temperature = 10.0mV")
{
    const auto VOLTAGE = 10.0_mV;
    REQUIRE(Approx(961.5).epsilon(EPSILON) == Thermocouple::calculate<TypeR>(VOLTAGE));
}

TEST_CASE("TypeR - Negative Voltage To Temperature = -0.1mV")
{
    const auto VOLTAGE = Voltage{-0.1};
    REQUIRE(Approx(-19.994).epsilon(EPSILON) == Thermocouple::calculate<TypeR>(VOLTAGE));
}

TEST_CASE("TypeR - Positive Temperature To Voltage = 1111.016°C")
{
    const auto TEMP = 1111.016_Temp;
    REQUIRE(Approx(12.0).epsilon(EPSILON) == Thermocouple::calculate<TypeR>(TEMP));
}

TEST_CASE("TypeR - Positive Temperature To Voltage = 721.652°C")
{
    const auto TEMP = 721.652_Temp;
    REQUIRE(Approx(7.0).epsilon(EPSILON) == Thermocouple::calculate<TypeR>(TEMP));
}
