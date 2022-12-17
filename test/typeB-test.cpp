#include <TypeConversion.h>
#include <catch2/catch_all.hpp>

using namespace UnitLiterals;
constexpr double EPSILON = 0.1;

TEST_CASE("TypeB - Name test") { CHECK("TypeB" == TypeB::NAME); }

TEST_CASE("TypeB - Positive Voltage To Temperature = 0.5mV")
{
    const auto VOLTAGE = 0.5_mV;
    REQUIRE_THAT(Thermocouple::calculate<TypeB>(VOLTAGE), Catch::Matchers::WithinRel(321.9, EPSILON));
}

TEST_CASE("TypeB - Positive Voltage To Temperature = 2.2mV")
{
    const auto VOLTAGE = 2.2_mV;
    REQUIRE_THAT(Thermocouple::calculate<TypeB>(VOLTAGE), Catch::Matchers::WithinRel(665.4, EPSILON));
}

TEST_CASE("TypeB - Positive Temperature To Voltage = 321.9°C")
{
    const auto TEMPERATURE = 321.9_Temp;
    REQUIRE_THAT(Thermocouple::calculate<TypeB>(TEMPERATURE), Catch::Matchers::WithinRel(0.5, EPSILON));
}

TEST_CASE("TypeB - Positive Temperature To Voltage = 665.4°C")
{
    const auto TEMPERATURE = 665.4_Temp;
    REQUIRE_THAT(Thermocouple::calculate<TypeB>(TEMPERATURE), Catch::Matchers::WithinRel(2.2, EPSILON));
}
