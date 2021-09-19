#include "TypeConversion.h"

#include <fmt/format.h>

int main()
{
    constexpr auto milliVolt = 20.096;  // 100°C
    const double temp = internal::calculateInternal<Conversion::Temperature, TypeK>(milliVolt);
    const auto temp2 = calculate<Conversion::Temperature, TypeK, TypeE>(milliVolt);
    fmt::print("Temperature: {0:.2f} °C\nVoltage: {1:.2f} mV", temp, std::get<0>(temp2));
    fmt::print("Temperature: {0:.2f} °C\nVoltage: {1:.2f} mV", temp, std::get<1>(temp2));
    fmt::print("Temperature: {0:.2f} °C\nVoltage: {1:.2f} mV", temp, internal::calculateInternal<Conversion::Voltage, TypeK>(temp));
    return 0;
}