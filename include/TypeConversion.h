#pragma once
#include <TypeBCoefficients.h>
#include <TypeECoefficients.h>
#include <TypeJCoefficients.h>
#include <TypeKCoefficients.h>
#include <TypeNCoefficients.h>
#include <TypeRCoefficients.h>
#include <TypeSCoefficients.h>
#include <TypeTCoefficients.h>
#include <functional>
#include <tuple>

template<typename T, typename ValueType>
struct Result
{
    using Type = T;
    ValueType value;

    auto getValue() const noexcept { return value; }

    auto getName() const noexcept { return Type::NAME; }
};

template<class T, class>
using hook = T;

namespace Internal {
template<Conversion Target, typename T>
constexpr auto calculate(const auto& value) -> double
{
    if constexpr (std::is_same_v<T, TypeB> && (Target == Conversion::Temp))
    {
        return T::VoltageToTemperature::calculate(value);
    }
    else if constexpr ((std::is_same_v<T, TypeK> || std::is_same_v<T, TypeB>) &&(Target == Conversion::Volt))
    {
        return T::TemperatureToVoltage::calculate(value);
    }
    else
    {
        if constexpr (Target == Conversion::Temp)
        {
            return conversion<typename T::VoltageToTemperature::Positive, typename T::VoltageToTemperature::Negative, Target>(value);
        }
        else
        {
            return conversion<typename T::TemperatureToVoltage::Positive, typename T::TemperatureToVoltage::Negative, Target>(value);
        }
    }
}

template<typename T, Conversion ConversionTarget, size_t SIZE>
constexpr auto conversion(const std::array<double, SIZE>& values) -> std::array<double, SIZE>
{
    decltype(values) result;
    size_t index = 0;
    for (const auto& val : values, ++index)
    {
        result[index] = calculate<T, ConversionTarget>(val);
    }
    return result;
}

template<Conversion Target, typename... T>
constexpr auto calculation(const auto& value)
{
    if constexpr (sizeof...(T) > 1)
    {
        std::tuple<hook<Result<T, double>, T>...> result;
        std::apply([&](auto&... xs) { ((xs.value = Internal::calculate<Target, T>(value)), ...); }, result);
        return result;
    }
    else
    {
        // we know here that only one type is given
        return Internal::calculate<Target, std::tuple_element_t<0, std::tuple<T...>>>(value);
    }
}
}  // namespace Internal

namespace UnitLiterals {
constexpr auto operator""_Temp(long double d) { return Temperature{static_cast<Temperature::Type>(d)}; }
constexpr auto operator""_mV(long double d) { return Voltage{static_cast<Voltage::Type>(d)}; }
}  // namespace UnitLiterals

namespace Thermocouple {
template<typename... T>
constexpr auto calculate(const auto& value)
{
    static_assert(sizeof...(T) > 0, "Please give an type as template parameter.");
    if constexpr (std::is_same_v<std::remove_cvref_t<decltype(value)>, Temperature>)
    {
        return Internal::calculation<Conversion::Volt, T...>(value);
    }
    else
    {
        return Internal::calculation<Conversion::Temp, T...>(value);
    }
}
}  // namespace Thermocouple
