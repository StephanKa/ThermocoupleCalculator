#include "TypeConversion.h"

#include <fmt/format.h>

int main()
{
    constexpr auto milliVolt = 4.096;  // 100°C
    // only one type given
    const auto temp = calculate<Conversion::Temperature, TypeK>(milliVolt);
    fmt::print("Temperature: {0:.2f} °C\nVoltage: {1:.2f} mV\n", temp, calculate<Conversion::Voltage, TypeK>(temp));
    const auto temperatures = calculate<Conversion::Temperature, TypeK, TypeT>(milliVolt);
    fmt::print("{1} Temperature: {0:.2f} °C\n", std::get<0>(temperatures), TypeK::name);
    fmt::print("{1} Temperature: {0:.2f} °C\n", std::get<1>(temperatures), TypeT::name);
    return 0;
}