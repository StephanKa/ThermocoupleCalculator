#pragma once
#include <TypeB.h>
#include <TypeE.h>
#include <TypeJ.h>
#include <TypeK.h>
#include <TypeN.h>
#include <TypeR.h>
#include <TypeS.h>
#include <TypeT.h>
#include <functional>
#include <tuple>

namespace Thermocouple {
template<typename T, typename ValueType>
struct Result
{
    using Type = T;
    ValueType value;

    consteval auto getValue() const noexcept
    {
        return value;
    }
    consteval auto getName() const noexcept
    {
        return Type::NAME;
    }
};

template<class T, class>
using hook = T;
}// namespace Thermocouple

namespace Internal {
template<Helper::Conversion Target, typename T>
[[nodiscard]] constexpr auto calculate(const auto &value)
{
    if constexpr (std::is_same_v<T, TypeB> && (Target == Helper::Conversion::Temp)) {
        return T::VoltageToTemperature::calculate(value);
    } else if constexpr ((std::is_same_v<T, TypeK> || std::is_same_v<T, TypeB>)&&(Target == Helper::Conversion::Volt)) {
        return T::TemperatureToVoltage::calculate(value);
    } else {
        if constexpr (Target == Helper::Conversion::Temp) {
            return conversion<typename T::VoltageToTemperature::Positive, typename T::VoltageToTemperature::Negative, Target>(value);
        } else {
            return conversion<typename T::TemperatureToVoltage::Positive, typename T::TemperatureToVoltage::Negative, Target>(value);
        }
    }
}

template<typename T, Helper::Conversion ConversionTarget, size_t SIZE>
[[nodiscard]] constexpr auto conversion(const std::array<double, SIZE> &values)
{
    decltype(values) result;
    size_t index = 0;
    for (const auto &val : values, ++index) {
        result[index] = calculate<T, ConversionTarget>(val);
    }
    return result;
}

template<Helper::Conversion Target, typename... T>
[[nodiscard]] constexpr auto calculation(const auto &value)
{
    if constexpr (sizeof...(T) > 1) {
        std::tuple<Thermocouple::hook<Thermocouple::Result<T, double>, T>...> result;
        std::apply([&](auto &...xs) { ((xs.value = Internal::calculate<Target, T>(value)), ...); }, result);
        return result;
    } else {
        // we know here that only one type is given
        return Internal::calculate<Target, std::tuple_element_t<0, std::tuple<T...>>>(value);
    }
}
}// namespace Internal

namespace UnitLiterals {
consteval auto operator""_Temp(long double d)
{
    return Temperature{ static_cast<Temperature::Type>(d) };
}
consteval auto operator""_mV(long double d)
{
    return Voltage{ static_cast<Voltage::Type>(d) };
}
}// namespace UnitLiterals

namespace Thermocouple {
template<typename... T>
[[nodiscard]] constexpr auto calculate(const auto &value)
{
    static_assert(sizeof...(T) > 0, "Please give an type as template parameter.");
    if constexpr (std::is_same_v<std::remove_cvref_t<decltype(value)>, Temperature>) {
        return Internal::calculation<Helper::Conversion::Volt, T...>(value);
    } else {
        return Internal::calculation<Helper::Conversion::Temp, T...>(value);
    }
}
}// namespace Thermocouple
