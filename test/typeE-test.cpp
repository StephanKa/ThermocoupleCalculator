#include <TypeConversion.h>
#include <catch2/catch.hpp>

TEST_CASE("TypeE - Name test") { CHECK("TypeE" == TypeE::NAME); }

TEST_CASE("TypeE - Positive Voltage To Temperature = 4.096mV")
{
    const auto VOLTAGE = 4.096;
    REQUIRE(Approx(66.4).epsilon(0.1) == Thermocouple::calculate<Conversion::Temperature, TypeE>(VOLTAGE));
}

TEST_CASE("TypeE - Positive Voltage To Temperature = 10.0mV")
{
    const auto VOLTAGE = 10.0;
    REQUIRE(Approx(152.9).epsilon(0.1) == Thermocouple::calculate<Conversion::Temperature, TypeE>(VOLTAGE));
}

TEST_CASE("TypeE - Negative Voltage To Temperature = -1.0mV")
{
    const auto VOLTAGE = -1.0;
    REQUIRE(Approx(-17.3).epsilon(0.1) == Thermocouple::calculate<Conversion::Temperature, TypeE>(VOLTAGE));
}

TEST_CASE("TypeE - Negative Voltage To Temperature = -4.096mV")
{
    const auto VOLTAGE = -4.096;
    REQUIRE(Approx(-75.766).epsilon(0.1) == Thermocouple::calculate<Conversion::Temperature, TypeE>(VOLTAGE));
}

TEST_CASE("TypeE - Positive Temperature To Voltage = 66.4°C")
{
    const auto TEMPERATURE = 66.4;
    REQUIRE(Approx(4.096).epsilon(0.1) == Thermocouple::calculate<Conversion::Voltage, TypeE>(TEMPERATURE));
}

TEST_CASE("TypeE - Positive Temperature To Voltage = 152.9°C")
{
    const auto TEMPERATURE = 152.9;
    REQUIRE(Approx(10.0).epsilon(0.1) == Thermocouple::calculate<Conversion::Voltage, TypeE>(TEMPERATURE));
}

TEST_CASE("TypeE - Negative Temperature To Voltage = -17.3°C")
{
    const auto TEMPERATURE = -17.3;
    REQUIRE(Approx(-1.0).epsilon(0.1) == Thermocouple::calculate<Conversion::Voltage, TypeE>(TEMPERATURE));
}

TEST_CASE("TypeE - Negative Temperature To Voltage = -75.766°C")
{
    const auto TEMPERATURE = -75.766;
    REQUIRE(Approx(-4.096).epsilon(0.1) == Thermocouple::calculate<Conversion::Voltage, TypeE>(TEMPERATURE));
}
