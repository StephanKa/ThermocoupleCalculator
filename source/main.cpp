#include "TypeConversion.h"

#include <fmt/format.h>

int main()
{
    constexpr auto MILLI_VOLT = 4.096;  // 100 °C
    // only one type given
    constexpr auto TEMP = calculate<Conversion::Temperature, TypeK>(MILLI_VOLT);
    fmt::print("Temperature: {0:.2f} °C\nVoltage: {1:.2f} mV\n", TEMP, calculate<Conversion::Voltage, TypeK>(TEMP));
    constexpr auto TEMPERATURES = calculate<Conversion::Temperature, TypeK, TypeT>(MILLI_VOLT);
    fmt::print("{1} Temperature: {0:.2f} °C\n", std::get<0>(TEMPERATURES), TypeK::NAME);
    fmt::print("{1} Temperature: {0:.2f} °C\n", std::get<1>(TEMPERATURES), TypeT::NAME);
    return 0;
}
