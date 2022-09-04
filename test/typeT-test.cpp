#include <TypeConversion.h>
#include <catch2/catch.hpp>

constexpr double EPSILON = 0.1;

TEST_CASE("TypeT - Name test") { CHECK("TypeT" == TypeT::NAME); }

TEST_CASE("TypeT - Positive Voltage To Temperature = 4.096mV")
{
    const auto VOLTAGE = 4.096;
    REQUIRE(Approx(96.1).epsilon(EPSILON) == calculate<Conversion::Temperature, TypeT>(VOLTAGE));
}

TEST_CASE("TypeT - Positive Voltage To Temperature = 10.0mV")
{
    const auto VOLTAGE = 10.0;
    REQUIRE(Approx(213.3).epsilon(EPSILON) == calculate<Conversion::Temperature, TypeT>(VOLTAGE));
}

TEST_CASE("TypeT - Negative Voltage To Temperature = -1.0mV")
{
    const auto VOLTAGE = -1.0;
    REQUIRE(Approx(-26.6).epsilon(EPSILON) == calculate<Conversion::Temperature, TypeT>(VOLTAGE));
}

TEST_CASE("TypeT - Negative Voltage To Temperature = -3.9mV")
{
    const auto VOLTAGE = -3.9;
    REQUIRE(Approx(-119.1).epsilon(EPSILON) == calculate<Conversion::Temperature, TypeT>(VOLTAGE));
}

TEST_CASE("TypeT - Positive Temperature To Voltage = 249.76°C")
{
    const auto VOLTAGE = 249.76;
    REQUIRE(Approx(12.0).epsilon(EPSILON) == calculate<Conversion::Voltage, TypeT>(VOLTAGE));
}

TEST_CASE("TypeT - Positive Temperature To Voltage = 302.375°C")
{
    const auto VOLTAGE = 302.375;
    REQUIRE(Approx(15.0).epsilon(EPSILON) == calculate<Conversion::Voltage, TypeT>(VOLTAGE));
}

TEST_CASE("TypeT - Positive Temperature To Voltage = -87.008°C")
{
    const auto VOLTAGE = -87.008;
    REQUIRE(Approx(-3.0).epsilon(EPSILON) == calculate<Conversion::Voltage, TypeT>(VOLTAGE));
}

TEST_CASE("TypeT - Positive Temperature To Voltage = -26.649°C")
{
    const auto VOLTAGE = -26.649;
    REQUIRE(Approx(-1).epsilon(EPSILON) == calculate<Conversion::Voltage, TypeT>(VOLTAGE));
}
