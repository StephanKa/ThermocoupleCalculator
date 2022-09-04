#pragma once
#include <cmath>
#include <string_view>

namespace Math {
constexpr double pow(double x, int y) { return y == 0 ? 1.0 : x * pow(x, y - 1); }
constexpr int factorial(int x) { return x == 0 ? 1 : x * factorial(x - 1); }
}  // namespace Math

enum class Conversion
{
    Voltage,
    Temperature
};

template<typename T, Conversion TargetConversion> constexpr auto calculation(const T& coefficient, const double voltage) -> double
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
        result += coefficient.at(index) * Math::pow(voltage, static_cast<int>(index));
    }
    return result;
}

template<class Positive, class Negative, Conversion Type> constexpr auto conversion(const double voltage) -> double
{
    double degrees = 0.0;
    if (voltage >= Negative::LOWER_LIMIT && voltage <= Negative::UPPER_LIMIT)
    {
        degrees = calculation<decltype(Negative::COEFFICIENT), Type>(Negative::COEFFICIENT, voltage);
    }
    else if (voltage >= Positive::LOWER_LIMIT && voltage <= Positive::UPPER_LIMIT)
    {
        degrees = calculation<decltype(Positive::COEFFICIENT), Type>(Positive::COEFFICIENT, voltage);
    }
    return degrees;
}
