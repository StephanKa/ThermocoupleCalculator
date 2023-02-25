#include <TypeConversion.h>
#include <catch2/catch_all.hpp>

using namespace UnitLiterals;
constexpr double EPSILON = 0.1;
using ThermocoupleType = TypeR;

TEST_CASE("TypeR - Name test") { CHECK("TypeR" == ThermocoupleType::NAME); }

TEST_CASE("TypeR - Positive Voltage To Temperature = 4.096mV")
{
    constexpr auto VOLTAGE = 4.096_mV;
    constexpr auto RESULT = Thermocouple::calculate<ThermocoupleType>(VOLTAGE);
    REQUIRE_THAT(RESULT, Catch::Matchers::WithinRel(465.2, EPSILON));
}

TEST_CASE("TypeR - Positive Voltage To Temperature = 10.0mV")
{
    constexpr auto VOLTAGE = 10.0_mV;
    constexpr auto RESULT = Thermocouple::calculate<ThermocoupleType>(VOLTAGE);
    REQUIRE_THAT(RESULT, Catch::Matchers::WithinRel(961.5, EPSILON));
}

TEST_CASE("TypeR - Negative Voltage To Temperature = -0.1mV")
{
    constexpr auto VOLTAGE = Voltage{-0.1};
    constexpr auto RESULT = Thermocouple::calculate<ThermocoupleType>(VOLTAGE);
    REQUIRE_THAT(RESULT, Catch::Matchers::WithinRel(-19.994, EPSILON));
}

TEST_CASE("TypeR - Positive Temperature To Voltage = 1111.016Degrees")
{
    constexpr auto TEMP = 1111.016_Temp;
    constexpr auto RESULT = Thermocouple::calculate<ThermocoupleType>(TEMP);
    REQUIRE_THAT(RESULT, Catch::Matchers::WithinRel(12.0, EPSILON));
}

TEST_CASE("TypeR - Positive Temperature To Voltage = 721.652Degrees")
{
    constexpr auto TEMP = 721.652_Temp;
    constexpr auto RESULT = Thermocouple::calculate<ThermocoupleType>(TEMP);
    REQUIRE_THAT(RESULT, Catch::Matchers::WithinRel(7.0, EPSILON));
}
