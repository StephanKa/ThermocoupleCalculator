#include <TypeConversion.h>
#include <catch2/catch_all.hpp>

using namespace UnitLiterals;
constexpr double EPSILON = 0.1;

TEST_CASE("TypeS - Name test") { CHECK("TypeS" == TypeS::NAME); }

TEST_CASE("TypeS - Positive Voltage To Temperature = 4.096mV")
{
    const auto VOLTAGE = 4.096_mV;
    REQUIRE_THAT(Thermocouple::calculate<TypeS>(VOLTAGE), Catch::Matchers::WithinRel(486.1, EPSILON));
}

TEST_CASE("TypeS - Positive Voltage To Temperature = 10.0mV")
{
    const auto VOLTAGE = 10.0_mV;
    REQUIRE_THAT(Thermocouple::calculate<TypeS>(VOLTAGE), Catch::Matchers::WithinRel(1035.6, EPSILON));
}

TEST_CASE("TypeS - Negative Voltage To Temperature = -0.2mV")
{
    const auto VOLTAGE = Voltage{-0.2};
    REQUIRE_THAT(Thermocouple::calculate<TypeS>(VOLTAGE), Catch::Matchers::WithinRel(-41.3, EPSILON));
}

TEST_CASE("TypeS - Negative Voltage To Temperature = -0.1mV")
{
    const auto VOLTAGE = Voltage{-0.1};
    REQUIRE_THAT(Thermocouple::calculate<TypeS>(VOLTAGE), Catch::Matchers::WithinRel(-19.4, EPSILON));
}

TEST_CASE("TypeS - Positive Temperature To Voltage = 1204.11Degrees")
{
    const auto TEMP = 1204.11_Temp;
    REQUIRE_THAT(Thermocouple::calculate<TypeS>(TEMP), Catch::Matchers::WithinRel(12.0, EPSILON));
}

TEST_CASE("TypeS - Positive Temperature To Voltage = 1451.796Degrees")
{
    const auto TEMP = 1451.796_Temp;
    REQUIRE_THAT(Thermocouple::calculate<TypeS>(TEMP), Catch::Matchers::WithinRel(15.0, EPSILON));
}
