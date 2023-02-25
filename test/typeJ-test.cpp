#include <TypeConversion.h>
#include <catch2/catch_all.hpp>

using namespace UnitLiterals;
constexpr double EPSILON = 0.1;
using ThermocoupleType = TypeJ;

TEST_CASE("TypeJ - Name test") { CHECK("TypeJ" == ThermocoupleType::NAME); }

TEST_CASE("TypeJ - Positive Voltage To Temperature = 4.096mV")
{
    constexpr auto VOLTAGE = 4.096_mV;
    constexpr auto RESULT = Thermocouple::calculate<ThermocoupleType>(VOLTAGE);
    REQUIRE_THAT(RESULT, Catch::Matchers::WithinRel(78.3, EPSILON));
}

TEST_CASE("TypeJ - Positive Voltage To Temperature = 10.0mV")
{
    constexpr auto VOLTAGE = 10.0_mV;
    constexpr auto RESULT = Thermocouple::calculate<ThermocoupleType>(VOLTAGE);
    REQUIRE_THAT(RESULT, Catch::Matchers::WithinRel(185.9, EPSILON));
}

TEST_CASE("TypeJ - Negative Voltage To Temperature = -1.0mV")
{
    constexpr auto VOLTAGE = Voltage{-1.0};
    constexpr auto RESULT = Thermocouple::calculate<ThermocoupleType>(VOLTAGE);
    REQUIRE_THAT(RESULT, Catch::Matchers::WithinRel(-20.1, EPSILON));
}

TEST_CASE("TypeJ - Negative Voltage To Temperature = -4.096mV")
{
    constexpr auto VOLTAGE = Voltage{-4.096};
    constexpr auto RESULT = Thermocouple::calculate<ThermocoupleType>(VOLTAGE);
    REQUIRE_THAT(RESULT, Catch::Matchers::WithinRel(-87.2, EPSILON));
}

TEST_CASE("TypeJ - Positive Temperature To Voltage = 221.994Degrees")
{
    constexpr auto TEMP = 221.994_Temp;
    constexpr auto RESULT = Thermocouple::calculate<ThermocoupleType>(TEMP);
    REQUIRE_THAT(RESULT, Catch::Matchers::WithinRel(12.0, EPSILON));
}

TEST_CASE("TypeJ - Positive Temperature To Voltage = 276.043Degrees")
{
    constexpr auto TEMP = 276.043_Temp;
    constexpr auto RESULT = Thermocouple::calculate<ThermocoupleType>(TEMP);
    REQUIRE_THAT(RESULT, Catch::Matchers::WithinRel(15.0, EPSILON));
}

TEST_CASE("TypeJ - Positive Temperature To Voltage = -62.353Degrees")
{
    constexpr auto TEMP = Temperature{-62.353};
    constexpr auto RESULT = Thermocouple::calculate<ThermocoupleType>(TEMP);
    REQUIRE_THAT(RESULT, Catch::Matchers::WithinRel(-3.0, EPSILON));
}

TEST_CASE("TypeJ - Positive Temperature To Voltage = -109.079Degrees")
{
    constexpr auto TEMP = Temperature{-109.079};
    constexpr auto RESULT = Thermocouple::calculate<ThermocoupleType>(TEMP);
    REQUIRE_THAT(RESULT, Catch::Matchers::WithinRel(-5, EPSILON));
}
