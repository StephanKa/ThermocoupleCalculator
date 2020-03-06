#include <TypeRCoefficients.h>
#include <catch2/catch.hpp>

constexpr double EPSILON = 0.1;

TEST_CASE("TypeR - Positive Voltage To Temperature = 4.096mV")
{
    const auto voltage = 4.096;
    REQUIRE(Approx(465.2).epsilon(EPSILON) == TypeR::VoltageToTemperature::calculate(voltage));
}

TEST_CASE("TypeR - Positive Voltage To Temperature = 10.0mV")
{
    const auto voltage = 10.0;
    REQUIRE(Approx(961.5).epsilon(EPSILON) == TypeR::VoltageToTemperature::calculate(voltage));
}

TEST_CASE("TypeR - Negative Voltage To Temperature = -0.1mV")
{
    const auto voltage = -0.1;
    REQUIRE(Approx(-19.994).epsilon(EPSILON) == TypeR::VoltageToTemperature::calculate(voltage));
}

TEST_CASE("TypeR - Positive Temperature To Voltage = 1111.016°C")
{
    const auto voltage = 1111.016;
    REQUIRE(Approx(12.0).epsilon(EPSILON) == TypeR::TemperatureToVoltage::calculate(voltage));
}

TEST_CASE("TypeR - Positive Temperature To Voltage = 721.652°C")
{
    const auto voltage = 721.652;
    REQUIRE(Approx(7.0).epsilon(EPSILON) == TypeR::TemperatureToVoltage::calculate(voltage));
}