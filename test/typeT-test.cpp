#include <TypeConversion.h>
#include <catch2/catch_all.hpp>

using namespace UnitLiterals;
constexpr double EPSILON = 0.1;

TEST_CASE("TypeT - Name test") { CHECK("TypeT" == TypeT::NAME); }

TEST_CASE("TypeT - Positive Voltage To Temperature = 4.096mV")
{
    const auto VOLTAGE = 4.096_mV;
    REQUIRE_THAT(Thermocouple::calculate<TypeT>(VOLTAGE), Catch::Matchers::WithinRel(96.1, EPSILON));
}

TEST_CASE("TypeT - Positive Voltage To Temperature = 10.0mV")
{
    const auto VOLTAGE = 10.0_mV;
    REQUIRE_THAT(Thermocouple::calculate<TypeT>(VOLTAGE), Catch::Matchers::WithinRel(213.3, EPSILON));
}

TEST_CASE("TypeT - Negative Voltage To Temperature = -1.0mV")
{
    const auto VOLTAGE = Voltage{-1.0};
    REQUIRE_THAT(Thermocouple::calculate<TypeT>(VOLTAGE), Catch::Matchers::WithinRel(-26.6, EPSILON));
}

TEST_CASE("TypeT - Negative Voltage To Temperature = -3.9mV")
{
    const auto VOLTAGE = Voltage{-3.9};
    REQUIRE_THAT(Thermocouple::calculate<TypeT>(VOLTAGE), Catch::Matchers::WithinRel(-119.1, EPSILON));
}

TEST_CASE("TypeT - Positive Temperature To Voltage = 249.76°C")
{
    const auto TEMP = 249.76_Temp;
    REQUIRE_THAT(Thermocouple::calculate<TypeT>(TEMP), Catch::Matchers::WithinRel(12.0, EPSILON));
}

TEST_CASE("TypeT - Positive Temperature To Voltage = 302.375°C")
{
    const auto TEMP = 302.375_Temp;
    REQUIRE_THAT(Thermocouple::calculate<TypeT>(TEMP), Catch::Matchers::WithinRel(15.0, EPSILON));
}

TEST_CASE("TypeT - Positive Temperature To Voltage = -87.008°C")
{
    const auto TEMP = Temperature{-87.008};
    REQUIRE_THAT(Thermocouple::calculate<TypeT>(TEMP), Catch::Matchers::WithinRel(-3.0, EPSILON));
}

TEST_CASE("TypeT - Positive Temperature To Voltage = -26.649°C")
{
    const auto TEMP = Temperature{-26.649};
    REQUIRE_THAT(Thermocouple::calculate<TypeT>(TEMP), Catch::Matchers::WithinRel(-1, EPSILON));
}
