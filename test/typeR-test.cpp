#include <TypeConversion.h>
#include <catch2/catch_all.hpp>

using namespace UnitLiterals;
constexpr double EPSILON = 0.1;

TEST_CASE("TypeR - Name test") { CHECK("TypeR" == TypeR::NAME); }

TEST_CASE("TypeR - Positive Voltage To Temperature = 4.096mV")
{
    const auto VOLTAGE = 4.096_mV;
    REQUIRE_THAT(Thermocouple::calculate<TypeR>(VOLTAGE), Catch::Matchers::WithinRel(465.2, EPSILON));
}

TEST_CASE("TypeR - Positive Voltage To Temperature = 10.0mV")
{
    const auto VOLTAGE = 10.0_mV;
    REQUIRE_THAT(Thermocouple::calculate<TypeR>(VOLTAGE), Catch::Matchers::WithinRel(961.5, EPSILON));
}

TEST_CASE("TypeR - Negative Voltage To Temperature = -0.1mV")
{
    const auto VOLTAGE = Voltage{-0.1};
    REQUIRE_THAT(Thermocouple::calculate<TypeR>(VOLTAGE), Catch::Matchers::WithinRel(-19.994, EPSILON));
}

TEST_CASE("TypeR - Positive Temperature To Voltage = 1111.016Degrees")
{
    const auto TEMP = 1111.016_Temp;
    REQUIRE_THAT(Thermocouple::calculate<TypeR>(TEMP), Catch::Matchers::WithinRel(12.0, EPSILON));
}

TEST_CASE("TypeR - Positive Temperature To Voltage = 721.652Degrees")
{
    const auto TEMP = 721.652_Temp;
    REQUIRE_THAT(Thermocouple::calculate<TypeR>(TEMP), Catch::Matchers::WithinRel(7.0, EPSILON));
}
