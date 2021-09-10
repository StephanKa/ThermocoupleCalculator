#include "TypeConversion.h"

#include <fmt/format.h>

int main()
{
    constexpr auto milliVolt = 4.096;  // 100°C
    const double temp = calculate<TypeK, Conversion::Temperature>(milliVolt);
    fmt::print("Temperature: {0:.2f} °C\nVoltage: {1:.2f} mV", temp, calculate<TypeK, Conversion::Voltage>(temp));
    return 0;
}