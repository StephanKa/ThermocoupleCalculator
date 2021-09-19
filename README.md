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
    constexpr auto milliVolt = 4.096;  // 100°C
    // only one type given
    const auto temp = calculate<Conversion::Temperature, TypeK>(milliVolt);
    fmt::print("Temperature: {0:.2f} °C\nVoltage: {1:.2f} mV\n", temp, calculate<Conversion::Voltage, TypeK>(temp));
    const auto temperatures = calculate<Conversion::Temperature, TypeK, TypeT>(milliVolt);
    fmt::print("TypeK Temperature: {0:.2f} °C\n", std::get<0>(temperatures));
    fmt::print("TypeT Temperature: {0:.2f} °C\n", std::get<1>(temperatures));
    return 0;
}
```

## To-Do
