#include <TypeConversion.h>
#include <catch2/catch_all.hpp>

using namespace UnitLiterals;
constexpr double EPSILON = 0.1;
using ThermocoupleType = TypeS;

TEST_CASE("TypeS - Name test") { CHECK("TypeS" == ThermocoupleType::NAME); }

TEST_CASE("TypeS - Positive Voltage To Temperature = 4.096mV")
{
    constexpr auto VOLTAGE = 4.096_mV;
    constexpr auto RESULT = Thermocouple::calculate<ThermocoupleType>(VOLTAGE);
    REQUIRE_THAT(RESULT, Catch::Matchers::WithinRel(486.1, EPSILON));
}

TEST_CASE("TypeS - Positive Voltage To Temperature = 10.0mV")
{
    constexpr auto VOLTAGE = 10.0_mV;
    constexpr auto RESULT = Thermocouple::calculate<ThermocoupleType>(VOLTAGE);
    REQUIRE_THAT(RESULT, Catch::Matchers::WithinRel(1035.6, EPSILON));
}

TEST_CASE("TypeS - Negative Voltage To Temperature = -0.2mV")
{
    constexpr auto VOLTAGE = Voltage{-0.2};
    constexpr auto RESULT = Thermocouple::calculate<ThermocoupleType>(VOLTAGE);
    REQUIRE_THAT(RESULT, Catch::Matchers::WithinRel(-41.3, EPSILON));
}

TEST_CASE("TypeS - Negative Voltage To Temperature = -0.1mV")
{
    constexpr auto VOLTAGE = Voltage{-0.1};
    constexpr auto RESULT = Thermocouple::calculate<ThermocoupleType>(VOLTAGE);
    REQUIRE_THAT(RESULT, Catch::Matchers::WithinRel(-19.4, EPSILON));
}

TEST_CASE("TypeS - Positive Temperature To Voltage = 1204.11Degrees")
{
    constexpr auto TEMP = 1204.11_Temp;
    constexpr auto RESULT = Thermocouple::calculate<ThermocoupleType>(TEMP);
    REQUIRE_THAT(RESULT, Catch::Matchers::WithinRel(12.0, EPSILON));
}

TEST_CASE("TypeS - Positive Temperature To Voltage = 1451.796Degrees")
{
    constexpr auto TEMP = 1451.796_Temp;
    constexpr auto RESULT = Thermocouple::calculate<ThermocoupleType>(TEMP);
    REQUIRE_THAT(RESULT, Catch::Matchers::WithinRel(15.0, EPSILON));
}
