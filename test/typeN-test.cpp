#include <TypeConversion.h>
#include <catch2/catch_all.hpp>

using namespace UnitLiterals;
constexpr double EPSILON = 0.1;
using ThermocoupleType = TypeN;

TEST_CASE("TypeN - Name test") { CHECK("TypeN" == ThermocoupleType::NAME); }

TEST_CASE("TypeN - Positive Voltage To Temperature = 4.096mV")
{
    constexpr auto VOLTAGE = 4.096_mV;
    constexpr auto RESULT = Thermocouple::calculate<ThermocoupleType>(VOLTAGE);
    REQUIRE_THAT(RESULT, Catch::Matchers::WithinRel(143.4, EPSILON));
}

TEST_CASE("TypeN - Positive Voltage To Temperature = 10.0mV")
{
    constexpr auto VOLTAGE = 10.0_mV;
    constexpr auto RESULT = Thermocouple::calculate<ThermocoupleType>(VOLTAGE);
    REQUIRE_THAT(RESULT, Catch::Matchers::WithinRel(318.5, EPSILON));
}

TEST_CASE("TypeN - Negative Voltage To Temperature = -1.0mV")
{
    constexpr auto VOLTAGE = Voltage{-1.0};
    constexpr auto RESULT = Thermocouple::calculate<ThermocoupleType>(VOLTAGE);
    REQUIRE_THAT(RESULT, Catch::Matchers::WithinRel(-39.1, EPSILON));
}

TEST_CASE("TypeN - Negative Voltage To Temperature = -3.9mV")
{
    constexpr auto VOLTAGE = Voltage{-3.9};
    constexpr auto RESULT = Thermocouple::calculate<ThermocoupleType>(VOLTAGE);
    REQUIRE_THAT(RESULT, Catch::Matchers::WithinRel(-191.393, EPSILON));
}

TEST_CASE("TypeN - Positive Temperature To Voltage = 373.637Degrees")
{
    constexpr auto TEMP = 373.637_Temp;
    constexpr auto RESULT = Thermocouple::calculate<ThermocoupleType>(TEMP);
    REQUIRE_THAT(RESULT, Catch::Matchers::WithinRel(12.0, EPSILON));
}

TEST_CASE("TypeN - Positive Temperature To Voltage = 454.064Degrees")
{
    constexpr auto TEMP = 454.064_Temp;
    constexpr auto RESULT = Thermocouple::calculate<ThermocoupleType>(TEMP);
    REQUIRE_THAT(RESULT, Catch::Matchers::WithinRel(15.0, EPSILON));
}

TEST_CASE("TypeN - Positive Temperature To Voltage = -130.323Degrees")
{
    constexpr auto TEMP = Temperature{-130.323};
    constexpr auto RESULT = Thermocouple::calculate<ThermocoupleType>(TEMP);
    REQUIRE_THAT(RESULT, Catch::Matchers::WithinRel(-3.0, EPSILON));
}

TEST_CASE("TypeN - Positive Temperature To Voltage = -39.084Degrees")
{
    constexpr auto TEMP = Temperature{-39.084};
    constexpr auto RESULT = Thermocouple::calculate<ThermocoupleType>(TEMP);
    REQUIRE_THAT(RESULT, Catch::Matchers::WithinRel(-1, EPSILON));
}
