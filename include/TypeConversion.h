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
#include <iostream>
#include <tuple>
#include <vector>

namespace internal {
template<Conversion Target, typename T> auto calculateInternal(double const value) -> double
{
    if constexpr (std::is_same_v<T, TypeB> && Target == Conversion::Temperature)
    {
        return T::VoltageToTemperature::calculate(value);
    }
    else if constexpr ((std::is_same_v<T, TypeK> || std::is_same_v<T, TypeB>) &&Target == Conversion::Voltage)
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

template<typename T, Conversion ConversionTarget> auto conversion(std::vector<double> const& values) -> std::vector<double>
{
    std::vector<double> result;
    result.reserve(values.size());
    for (const auto& val : values)
    {
        result.push_back(calculate<T, ConversionTarget>(val));
    }
    return result;
}
}  // namespace internal

template<class T, class> using hook = T;

template<Conversion Target, typename... T> auto calculate(double const value)
{
    static_assert(sizeof...(T) > 0, "Please give an type as template parameter.");
    if constexpr (sizeof...(T) > 1)
    {
        std::tuple<hook<double, T>...> result;
        std::apply([&](auto&... xs) { ((xs = internal::calculateInternal<Target, T>(value)), ...); }, result);
        return result;
    }
    else
    {
        // we know here that only one type was given
        return internal::calculateInternal<Target, std::tuple_element_t<0, std::tuple<T...>>>(value);
    }
}
