#include "TypeConversion.h"

#include <array>
#include <fmt/format.h>

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
    return std::apply([](auto... n) { return std::array{ Result{ n.value, n.getName() }... }; }, t);
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
