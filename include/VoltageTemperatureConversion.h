#pragma once
#include <TypeBCoefficients.h>
#include <TypeECoefficients.h>
#include <TypeJCoefficients.h>
#include <TypeKCoefficients.h>
#include <TypeNCoefficients.h>
#include <TypeRCoefficients.h>
#include <TypeSCoefficients.h>
#include <TypeTCoefficients.h>
#include <cmath>

template <typename T>
double temperature(T& coefficient, double const voltage)
{
    double result = coefficient[0];
    for (int index = 1; index < static_cast<int>(coefficient.size()); index++)
    {
        result += coefficient.at(index) * std::pow(voltage, static_cast<double>(index));
    }
    return result;
}

template <typename T>
double voltage(T& coefficient, double const voltage)
{
    double result = 0.0;
    for (int index = 0; index < static_cast<int>(coefficient.size()); index++)
    {
        result += coefficient.at(index) * std::pow(voltage, static_cast<double>(index));
    }
    return result;
}

template <typename ThermocoupleType, typename Conversion>
static double calculate(double const value)
{
    double ret = 0.0;
    if (value >= Conversion::Negative::lowerLimit && value <= Conversion::Negative::upperLimit)
    {
        if constexpr (std::is_same_v<Conversion, typename ThermocoupleType::TemperatureToVoltage>)
        {
            ret = voltage<decltype(Conversion::Negative::coefficient)>(Conversion::Negative::coefficient, value);
        }
        else if constexpr (std::is_same_v<Conversion, typename ThermocoupleType::VoltageToTemperature>)
        {
            ret = temperature<decltype(Conversion::Negative::coefficient)>(Conversion::Negative::coefficient, value);
        }
    }
    else if (value >= Conversion::Positive::lowerLimit && value <= Conversion::Positive::upperLimit)
    {
        if constexpr (std::is_same_v<Conversion, typename ThermocoupleType::TemperatureToVoltage>)
        {
            if constexpr (std::is_same_v<ThermocoupleType, TypeK>)
            {
                Conversion::calculate(ret, value);
            }
            else
            {
                ret = voltage<decltype(Conversion::Positive::coefficient)>(Conversion::Positive::coefficient, value);
            }
        }
        else if constexpr (std::is_same_v<Conversion, typename ThermocoupleType::VoltageToTemperature>)
        {
            ret = temperature<decltype(Conversion::Positive::coefficient)>(Conversion::Positive::coefficient, value);
        }
    }
    return ret;
}
