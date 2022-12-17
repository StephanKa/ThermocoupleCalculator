#include <TypeConversion.h>
#include <catch2/catch_test_macros.hpp>

using namespace UnitLiterals;
constexpr double EPSILON = 0.1;

TEST_CASE("TypeS - Name test") { CHECK("TypeS" == TypeS::NAME); }

TEST_CASE("TypeS - Positive Voltage To Temperature = 4.096mV")
{
    const auto VOLTAGE = 4.096_mV;
    REQUIRE(Approx(486.1).epsilon(EPSILON) == Thermocouple::calculate<TypeS>(VOLTAGE));
}

TEST_CASE("TypeS - Positive Voltage To Temperature = 10.0mV")
{
    const auto VOLTAGE = 10.0_mV;
    REQUIRE(Approx(1035.6).epsilon(EPSILON) == Thermocouple::calculate<TypeS>(VOLTAGE));
}

TEST_CASE("TypeS - Negative Voltage To Temperature = -0.2mV")
{
    const auto VOLTAGE = Voltage{-0.2};
    REQUIRE(Approx(-41.3).epsilon(EPSILON) == Thermocouple::calculate<TypeS>(VOLTAGE));
}

TEST_CASE("TypeS - Negative Voltage To Temperature = -0.1mV")
{
    const auto VOLTAGE = Voltage{-0.1};
    REQUIRE(Approx(-19.4).epsilon(EPSILON) == Thermocouple::calculate<TypeS>(VOLTAGE));
}

TEST_CASE("TypeS - Positive Temperature To Voltage = 1204.11°C")
{
    const auto TEMP = 1204.11_Temp;
    REQUIRE(Approx(12.0).epsilon(EPSILON) == Thermocouple::calculate<TypeS>(TEMP));
}

TEST_CASE("TypeS - Positive Temperature To Voltage = 1451.796°C")
{
    const auto TEMP = 1451.796_Temp;
    REQUIRE(Approx(15.0).epsilon(EPSILON) == Thermocouple::calculate<TypeS>(TEMP));
}
