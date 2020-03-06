#include "TypeKCoefficients.h"
#include <iostream>

int main(int argc, char* argv[])
{
    const double milliVolt = 4.096;
    const double temp = TypeK::VoltageToTemperature::calculate(milliVolt);
    std::cout << "Temperature: " << temp << "\n";
}