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
#include <vector>

namespace Internal {
template<Conversion Target, typename T>
constexpr auto calculateInternal(const double value) -> double
{
    if constexpr (std::is_same_v<T, TypeB> && (Target == Conversion::Temperature))
    {
        return T::VoltageToTemperature::calculate(value);
    }
    else if constexpr ((std::is_same_v<T, TypeK> || std::is_same_v<T, TypeB>) &&(Target == Conversion::Voltage))
    {
        return T::TemperatureToVoltage::calculate(value);
    }
    else
    {
        if constexpr (Target == Conversion::Temperature)
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
}  // namespace Internal

template<class T, class>
using hook = T;

template<typename T, typename ValueType>
struct Result
{
    using Type = T;
    ValueType value;

    auto getValue() const noexcept { return value; }

    auto getName() const noexcept { return Type::NAME; }
};

namespace Thermocouple {
template<Conversion Target, typename... T>
constexpr auto calculate(const double value)
{
    static_assert(sizeof...(T) > 0, "Please give an type as template parameter.");
    if constexpr (sizeof...(T) > 1)
    {
        std::tuple<hook<Result<T, double>, T>...> result;
        std::apply([&](auto&... xs) { ((xs.value = Internal::calculateInternal<Target, T>(value)), ...); }, result);
        return result;
    }
    else
    {
        // we know here that only one type is given
        return Internal::calculateInternal<Target, std::tuple_element_t<0, std::tuple<T...>>>(value);
    }
}
}  // namespace Thermocouple
