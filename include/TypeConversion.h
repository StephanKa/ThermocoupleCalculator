#pragma once
#include <TypeBCoefficients.h>
#include <TypeECoefficients.h>
#include <TypeJCoefficients.h>
#include <TypeKCoefficients.h>
#include <TypeNCoefficients.h>
#include <TypeRCoefficients.h>
#include <TypeSCoefficients.h>
#include <TypeTCoefficients.h>
#include <vector>

template<typename T, Conversion Target> auto calculate(double const value) -> double
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
