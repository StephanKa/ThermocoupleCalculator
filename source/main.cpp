#include "VoltageTemperatureConversion.h"
#include <iostream>

int main(int argc, char* argv[])
{
    const double milliVolt = 4.096;
    const double temp = calculate<TypeK, TypeK::VoltageToTemperature>(milliVolt);
    std::cout << "Temperature: " << temp << "\n";
    std::cout << "Voltage: " << calculate<TypeK, TypeK::TemperatureToVoltage>(temp) << "\n";
}