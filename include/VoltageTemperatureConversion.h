#pragma once
#include <cmath>

enum class Conversion
{
    Voltage,
    Temperature
};

template <typename T, Conversion TargetConversion>
constexpr auto calculation(T& coefficient, double const voltage) -> double
{
    double result = 0.0;
    size_t index = 0;
    if constexpr (TargetConversion == Conversion::Temperature)
    {
        result = coefficient[0];
        index = 1;
    }
    for (; index < coefficient.size(); index++)
    {
        result += coefficient.at(index) * std::pow(voltage, static_cast<double>(index));
    }
    return result;
}

template <class Positive, class Negative, Conversion Type>
constexpr auto conversion(double const voltage) -> double
{
    double degrees = 0.0;
    if (voltage >= Negative::lowerLimit && voltage <= Negative::upperLimit)
    {
        degrees = calculation<decltype(Negative::coefficient), Type>(Negative::coefficient, voltage);
    }
    else if (voltage >= Positive::lowerLimit && voltage <= Positive::upperLimit)
    {
        degrees = calculation<decltype(Positive::coefficient), Type>(Positive::coefficient, voltage);
    }
    return degrees;
}
