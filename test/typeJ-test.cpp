#include <TypeConversion.h>
#include <catch2/catch_all.hpp>

using namespace UnitLiterals;
constexpr double EPSILON = 0.1;

TEST_CASE("TypeJ - Name test") { CHECK("TypeJ" == TypeJ::NAME); }

TEST_CASE("TypeJ - Positive Voltage To Temperature = 4.096mV")
{
    const auto VOLTAGE = 4.096_mV;
    REQUIRE_THAT(Thermocouple::calculate<TypeJ>(VOLTAGE), Catch::Matchers::WithinRel(78.3, EPSILON));
}

TEST_CASE("TypeJ - Positive Voltage To Temperature = 10.0mV")
{
    const auto VOLTAGE = 10.0_mV;
    REQUIRE_THAT(Thermocouple::calculate<TypeJ>(VOLTAGE), Catch::Matchers::WithinRel(185.9, EPSILON));
}

TEST_CASE("TypeJ - Negative Voltage To Temperature = -1.0mV")
{
    const auto VOLTAGE = Voltage{-1.0};
    REQUIRE_THAT(Thermocouple::calculate<TypeJ>(VOLTAGE), Catch::Matchers::WithinRel(-20.1, EPSILON));
}

TEST_CASE("TypeJ - Negative Voltage To Temperature = -4.096mV")
{
    const auto VOLTAGE = Voltage{-4.096};
    REQUIRE_THAT(Thermocouple::calculate<TypeJ>(VOLTAGE), Catch::Matchers::WithinRel(-87.2, EPSILON));
}

TEST_CASE("TypeJ - Positive Temperature To Voltage = 221.994Degrees")
{
    const auto TEMP = 221.994_Temp;
    REQUIRE_THAT(Thermocouple::calculate<TypeJ>(TEMP), Catch::Matchers::WithinRel(12.0, EPSILON));
}

TEST_CASE("TypeJ - Positive Temperature To Voltage = 276.043Degrees")
{
    const auto TEMP = 276.043_Temp;
    REQUIRE_THAT(Thermocouple::calculate<TypeJ>(TEMP), Catch::Matchers::WithinRel(15.0, EPSILON));
}

TEST_CASE("TypeJ - Positive Temperature To Voltage = -62.353Degrees")
{
    const auto TEMP = Temperature{-62.353};
    REQUIRE_THAT(Thermocouple::calculate<TypeJ>(TEMP), Catch::Matchers::WithinRel(-3.0, EPSILON));
}

TEST_CASE("TypeJ - Positive Temperature To Voltage = -109.079Degrees")
{
    const auto TEMP = Temperature{-109.079};
    REQUIRE_THAT(Thermocouple::calculate<TypeJ>(TEMP), Catch::Matchers::WithinRel(-5, EPSILON));
}
