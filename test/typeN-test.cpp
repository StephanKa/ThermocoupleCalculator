#include <TypeConversion.h>
#include <catch2/catch_all.hpp>

using namespace UnitLiterals;
constexpr double EPSILON = 0.1;

TEST_CASE("TypeN - Name test") { CHECK("TypeN" == TypeN::NAME); }

TEST_CASE("TypeN - Positive Voltage To Temperature = 4.096mV")
{
    const auto VOLTAGE = 4.096_mV;
    REQUIRE_THAT(Thermocouple::calculate<TypeN>(VOLTAGE), Catch::Matchers::WithinRel(143.4, EPSILON));
}

TEST_CASE("TypeN - Positive Voltage To Temperature = 10.0mV")
{
    const auto VOLTAGE = 10.0_mV;
    REQUIRE_THAT(Thermocouple::calculate<TypeN>(VOLTAGE), Catch::Matchers::WithinRel(318.5, EPSILON));
}

TEST_CASE("TypeN - Negative Voltage To Temperature = -1.0mV")
{
    const auto VOLTAGE = Voltage{-1.0};
    REQUIRE_THAT(Thermocouple::calculate<TypeN>(VOLTAGE), Catch::Matchers::WithinRel(-39.1, EPSILON));
}

TEST_CASE("TypeN - Negative Voltage To Temperature = -3.9mV")
{
    const auto VOLTAGE = Voltage{-3.9};
    REQUIRE_THAT(Thermocouple::calculate<TypeN>(VOLTAGE), Catch::Matchers::WithinRel(-191.393, EPSILON));
}

TEST_CASE("TypeN - Positive Temperature To Voltage = 373.637Degrees")
{
    const auto TEMP = 373.637_Temp;
    REQUIRE_THAT(Thermocouple::calculate<TypeN>(TEMP), Catch::Matchers::WithinRel(12.0, EPSILON));
}

TEST_CASE("TypeN - Positive Temperature To Voltage = 454.064Degrees")
{
    const auto TEMP = 454.064_Temp;
    REQUIRE_THAT(Thermocouple::calculate<TypeN>(TEMP), Catch::Matchers::WithinRel(15.0, EPSILON));
}

TEST_CASE("TypeN - Positive Temperature To Voltage = -130.323Degrees")
{
    const auto TEMP = Temperature{-130.323};
    REQUIRE_THAT(Thermocouple::calculate<TypeN>(TEMP), Catch::Matchers::WithinRel(-3.0, EPSILON));
}

TEST_CASE("TypeN - Positive Temperature To Voltage = -39.084Degrees")
{
    const auto TEMP = Temperature{-39.084};
    REQUIRE_THAT(Thermocouple::calculate<TypeN>(TEMP), Catch::Matchers::WithinRel(-1, EPSILON));
}
