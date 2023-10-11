#include <TypeConversion.h>
#include <catch2/catch_all.hpp>

using namespace UnitLiterals;
constexpr double EPSILON = 0.1;
using ThermocoupleType = TypeB;

TEST_CASE("TypeB - Name test")
{
    CHECK("TypeB" == ThermocoupleType::NAME);
}

TEST_CASE("TypeB - Positive Voltage To Temperature = 0.5mV")
{
    constexpr auto VOLTAGE = 0.5_mV;
    constexpr auto RESULT = Thermocouple::calculate<ThermocoupleType>(VOLTAGE);
    REQUIRE_THAT(RESULT, Catch::Matchers::WithinRel(321.9, EPSILON));
}

TEST_CASE("TypeB - Positive Voltage To Temperature = 2.2mV")
{
    constexpr auto VOLTAGE = 2.2_mV;
    constexpr auto RESULT = Thermocouple::calculate<ThermocoupleType>(VOLTAGE);
    REQUIRE_THAT(RESULT, Catch::Matchers::WithinRel(665.4, EPSILON));
}

TEST_CASE("TypeB - Positive Temperature To Voltage = 321.9Degrees")
{
    constexpr auto TEMPERATURE = 321.9_Temp;
    constexpr auto RESULT = Thermocouple::calculate<ThermocoupleType>(TEMPERATURE);
    REQUIRE_THAT(RESULT, Catch::Matchers::WithinRel(0.5, EPSILON));
}

TEST_CASE("TypeB - Positive Temperature To Voltage = 665.4Degrees")
{
    constexpr auto TEMPERATURE = 665.4_Temp;
    constexpr auto RESULT = Thermocouple::calculate<ThermocoupleType>(TEMPERATURE);
    REQUIRE_THAT(RESULT, Catch::Matchers::WithinRel(2.2, EPSILON));
}
