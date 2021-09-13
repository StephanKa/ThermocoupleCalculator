# ThermocoupleCalculator

[![C/C++ CMake CI](https://github.com/StephanKa/ThermocoupleCalculator/actions/workflows/build_cmake.yml/badge.svg)](https://github.com/StephanKa/ThermocoupleCalculator/actions/workflows/build_cmake.yml)
[![CodeQL](https://github.com/StephanKa/ThermocoupleCalculator/actions/workflows/codeql-analysis.yml/badge.svg)](https://github.com/StephanKa/ThermocoupleCalculator/actions/workflows/codeql-analysis.yml)

## General

This code will calculate thermo voltages from a given temperature for a defined thermocouple type or calculates a temperatures from a given voltage.

The code based on the coefficients of the NIST database which can be found here: https://srdata.nist.gov/its90/download/type_<X>.tab

Supported thermocouple types are:

- Type-B
- Type-E
- Type-J
- Type-K
- Type-N
- Type-R
- Type-S
- Type-T

## Example

This example can be found under **source/main.cpp**

```c++
#include "TypeConversion.h"

#include <fmt/format.h>

int main()
{
    constexpr auto milliVolt = 4.096;  // 100°C
    const double temp = calculate<TypeK, Conversion::Temperature>(milliVolt);
    fmt::print("Temperature: {0:.2f} °C\nVoltage: {1:.2f} mV", temp, calculate<TypeK, Conversion::Voltage>(temp));
    return 0;
}
```

## To-Do

- [ ] add parameter pack for calculating multiple types at a time