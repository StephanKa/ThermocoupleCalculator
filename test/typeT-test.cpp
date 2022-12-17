#include <TypeConversion.h>
#include <catch2/catch_test_macros.hpp>

using namespace UnitLiterals;
constexpr double EPSILON = 0.1;

TEST_CASE("TypeT - Name test") { CHECK("TypeT" == TypeT::NAME); }

TEST_CASE("TypeT - Positive Voltage To Temperature = 4.096mV")
{
    const auto VOLTAGE = 4.096_mV;
    REQUIRE(Approx(96.1).epsilon(EPSILON) == Thermocouple::calculate<TypeT>(VOLTAGE));
}

TEST_CASE("TypeT - Positive Voltage To Temperature = 10.0mV")
{
    const auto VOLTAGE = 10.0_mV;
    REQUIRE(Approx(213.3).epsilon(EPSILON) == Thermocouple::calculate<TypeT>(VOLTAGE));
}

TEST_CASE("TypeT - Negative Voltage To Temperature = -1.0mV")
{
    const auto VOLTAGE = Voltage{-1.0};
    REQUIRE(Approx(-26.6).epsilon(EPSILON) == Thermocouple::calculate<TypeT>(VOLTAGE));
}

TEST_CASE("TypeT - Negative Voltage To Temperature = -3.9mV")
{
    const auto VOLTAGE = Voltage{-3.9};
    REQUIRE(Approx(-119.1).epsilon(EPSILON) == Thermocouple::calculate<TypeT>(VOLTAGE));
}

TEST_CASE("TypeT - Positive Temperature To Voltage = 249.76°C")
{
    const auto TEMP = 249.76_Temp;
    REQUIRE(Approx(12.0).epsilon(EPSILON) == Thermocouple::calculate<TypeT>(TEMP));
}

TEST_CASE("TypeT - Positive Temperature To Voltage = 302.375°C")
{
    const auto TEMP = 302.375_Temp;
    REQUIRE(Approx(15.0).epsilon(EPSILON) == Thermocouple::calculate<TypeT>(TEMP));
}

TEST_CASE("TypeT - Positive Temperature To Voltage = -87.008°C")
{
    const auto TEMP = Temperature{-87.008};
    REQUIRE(Approx(-3.0).epsilon(EPSILON) == Thermocouple::calculate<TypeT>(TEMP));
}

TEST_CASE("TypeT - Positive Temperature To Voltage = -26.649°C")
{
    const auto TEMP = Temperature{-26.649};
    REQUIRE(Approx(-1).epsilon(EPSILON) == Thermocouple::calculate<TypeT>(TEMP));
}
