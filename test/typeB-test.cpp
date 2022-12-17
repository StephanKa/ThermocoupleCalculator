#include <TypeConversion.h>
#include <catch2/catch_test_macros.hpp>

using namespace UnitLiterals;
constexpr double EPSILON = 0.1;

TEST_CASE("TypeB - Name test") { CHECK("TypeB" == TypeB::NAME); }

TEST_CASE("TypeB - Positive Voltage To Temperature = 0.5mV")
{
    const auto VOLTAGE = 0.5_mV;
    REQUIRE(Approx(321.9).epsilon(EPSILON) == Thermocouple::calculate<TypeB>(VOLTAGE));
}

TEST_CASE("TypeB - Positive Voltage To Temperature = 2.2mV")
{
    const auto VOLTAGE = 2.2_mV;
    REQUIRE(Approx(665.4).epsilon(EPSILON) == Thermocouple::calculate<TypeB>(VOLTAGE));
}

TEST_CASE("TypeB - Positive Temperature To Voltage = 321.9°C")
{
    const auto TEMPERATURE = 321.9_Temp;
    REQUIRE(Approx(0.5).epsilon(EPSILON) == Thermocouple::calculate<TypeB>(TEMPERATURE));
}

TEST_CASE("TypeB - Positive Temperature To Voltage = 665.4°C")
{
    const auto TEMPERATURE = 665.4_Temp;
    REQUIRE(Approx(2.2).epsilon(EPSILON) == Thermocouple::calculate<TypeB>(TEMPERATURE));
}
