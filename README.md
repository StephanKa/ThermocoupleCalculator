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
namespace {
using namespace UnitLiterals;
constexpr auto MILLI_VOLT = 4.096_mV;// 100 °C by TypeK

struct Result
{
    double value;
    std::string_view name;
};

}// namespace

template<typename Tuple>
[[nodiscard]] constexpr auto convertTupleToArray(Tuple &&t)
{
    return std::apply([](auto... n) { return std::array{ Result{ .value=n.value, .name=n.getName() }... }; }, t);
}

int main()
{
    fmt::print("Input voltage: {0:.3f} mV\n", MILLI_VOLT());

    // only one type given
    constexpr auto TEMP = Thermocouple::calculate<TypeK>(MILLI_VOLT);
    fmt::print("Temperature: {0:.2f} °C\nVoltage: {1:.2f} mV\n", TEMP, Thermocouple::calculate<TypeK>(Temperature{ TEMP }));

    constexpr auto TEMPERATURES = Thermocouple::calculate<TypeK, TypeT, TypeB, TypeE, TypeJ, TypeN, TypeR, TypeS>(MILLI_VOLT);
    for (const auto &temp : convertTupleToArray(TEMPERATURES)) {
        fmt::print("{1} Temperature: {0:.2f} °C\n", temp.value, temp.name);
    }

    return 0;
}
```

## To-Do
- [ ] Make types configurable in CMake
