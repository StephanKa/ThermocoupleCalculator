#include <TypeConversion.h>
#include <catch2/catch.hpp>

constexpr double EPSILON = 0.1;

TEST_CASE("TypeN - Name test") { CHECK("TypeN" == TypeN::NAME); }

TEST_CASE("TypeN - Positive Voltage To Temperature = 4.096mV")
{
    const auto VOLTAGE = 4.096;
    REQUIRE(Approx(143.4).epsilon(EPSILON) == calculate<Conversion::Temperature, TypeN>(VOLTAGE));
}

TEST_CASE("TypeN - Positive Voltage To Temperature = 10.0mV")
{
    const auto VOLTAGE = 10.0;
    REQUIRE(Approx(318.5).epsilon(EPSILON) == calculate<Conversion::Temperature, TypeN>(VOLTAGE));
}

TEST_CASE("TypeN - Negative Voltage To Temperature = -1.0mV")
{
    const auto VOLTAGE = -1.0;
    REQUIRE(Approx(-39.1).epsilon(EPSILON) == calculate<Conversion::Temperature, TypeN>(VOLTAGE));
}

TEST_CASE("TypeN - Negative Voltage To Temperature = -3.9mV")
{
    const auto VOLTAGE = -3.9;
    REQUIRE(Approx(-191.393).epsilon(EPSILON) == calculate<Conversion::Temperature, TypeN>(VOLTAGE));
}

TEST_CASE("TypeN - Positive Temperature To Voltage = 373.637°C")
{
    const auto VOLTAGE = 373.637;
    REQUIRE(Approx(12.0).epsilon(EPSILON) == calculate<Conversion::Voltage, TypeN>(VOLTAGE));
}

TEST_CASE("TypeN - Positive Temperature To Voltage = 454.064°C")
{
    const auto VOLTAGE = 454.064;
    REQUIRE(Approx(15.0).epsilon(EPSILON) == calculate<Conversion::Voltage, TypeN>(VOLTAGE));
}

TEST_CASE("TypeN - Positive Temperature To Voltage = -130.323°C")
{
    const auto VOLTAGE = -130.323;
    REQUIRE(Approx(-3.0).epsilon(EPSILON) == calculate<Conversion::Voltage, TypeN>(VOLTAGE));
}

TEST_CASE("TypeN - Positive Temperature To Voltage = -39.084°C")
{
    const auto VOLTAGE = -39.084;
    REQUIRE(Approx(-1).epsilon(EPSILON) == calculate<Conversion::Voltage, TypeN>(VOLTAGE));
}
