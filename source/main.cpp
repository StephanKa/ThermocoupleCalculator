#include "TypeConversion.h"

#include <fmt/format.h>

int main()
{
    using namespace UnitLiterals;

    constexpr auto MILLI_VOLT = 4.096_mV;  // 100 °C by TypeK
    fmt::print("Input voltage: {0:.3f} mV\n", MILLI_VOLT());

    // only one type given
    constexpr auto TEMP = Thermocouple::calculate<TypeK>(MILLI_VOLT);
    fmt::print("Temperature: {0:.2f} °C\nVoltage: {1:.2f} mV\n", TEMP, Thermocouple::calculate<TypeK>(Temperature{TEMP}));

    constexpr auto TEMPERATURES = Thermocouple::calculate<TypeK, TypeT, TypeB, TypeE, TypeJ, TypeN, TypeR, TypeS>(MILLI_VOLT);
    std::apply([](const auto&... val) { ((fmt::print("{1} Temperature: {0:.2f} °C\n", val.getValue(), val.getName())), ...); }, TEMPERATURES);

    return 0;
}
