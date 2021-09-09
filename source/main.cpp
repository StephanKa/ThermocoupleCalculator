#include "TypeConversion.h"

#include <iostream>

int main()
{
    const double milliVolt = 4.096;
    const double temp = calculate<TypeK, Conversion::Temperature>(milliVolt);
    std::cout << "Temperature: " << temp << "\n";
    std::cout << "Voltage: " << calculate<TypeK, Conversion::Voltage>(temp) << "\n";
    return 0;
}