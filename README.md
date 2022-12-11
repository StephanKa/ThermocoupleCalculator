# ThermocoupleCalculator

[![C/C++ CMake CI](https://github.com/StephanKa/ThermocoupleCalculator/actions/workflows/build_cmake.yml/badge.svg)](https://github.com/StephanKa/ThermocoupleCalculator/actions/workflows/build_cmake.yml)
[![CodeQL](https://github.com/StephanKa/ThermocoupleCalculator/actions/workflows/codeql-analysis.yml/badge.svg)](https://github.com/StephanKa/ThermocoupleCalculator/actions/workflows/codeql-analysis.yml)

## General

This code will calculate thermo voltages from a given temperature for a defined thermocouple type or calculates a temperatures from a given voltage.

The code based on the coefficients of the NIST database

Supported thermocouple types are:

- **[Type-B](https://srdata.nist.gov/its90/download/type_b.tab)**
- **[Type-E](https://srdata.nist.gov/its90/download/type_e.tab)**
- **[Type-J](https://srdata.nist.gov/its90/download/type_j.tab)**
- **[Type-K](https://srdata.nist.gov/its90/download/type_k.tab)**
- **[Type-N](https://srdata.nist.gov/its90/download/type_n.tab)**
- **[Type-R](https://srdata.nist.gov/its90/download/type_r.tab)**
- **[Type-S](https://srdata.nist.gov/its90/download/type_s.tab)**
- **[Type-T](https://srdata.nist.gov/its90/download/type_t.tab)**

## Example

This example can be found under **source/main.cpp**

```c++
#include "TypeConversion.h"

#include <fmt/format.h>

int main()
{
    constexpr auto MILLI_VOLT = 4.096;  // 100 °C
    fmt::print("Input voltage: {0:.3f} mV\n", MILLI_VOLT);
    // only one type given
    constexpr auto TEMP = Thermocouple::calculate<Conversion::Temperature, TypeK>(MILLI_VOLT);
    fmt::print("Temperature: {0:.2f} °C\nVoltage: {1:.2f} mV\n", TEMP, Thermocouple::calculate<Conversion::Voltage, TypeK>(TEMP));

    constexpr auto TEMPERATURES = Thermocouple::calculate<Conversion::Temperature, TypeK, TypeT, TypeB, TypeE, TypeJ, TypeN, TypeR, TypeS>(MILLI_VOLT);
    std::apply([](const auto&... val) { ((fmt::print("{1} Temperature: {0:.2f} °C\n", val.getValue(), val.getName())), ...); }, TEMPERATURES);

    return 0;
}
```

## To-Do
