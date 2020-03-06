#pragma once
#include <cmath>

template <typename T>
double calculateTemperature(T& coefficient, double const voltage)
{
    double result = coefficient[0];
    for (int index = 1; index < static_cast<int>(coefficient.size()); index++)
    {
        result += coefficient.at(index) * std::pow(voltage, static_cast<double>(index));
    }
    return result;
}

template <typename T>
double calculateVoltage(T& coefficient, double const voltage)
{
    double result = 0.0;
    for (int index = 0; index < static_cast<int>(coefficient.size()); index++)
    {
        result += coefficient.at(index) * std::pow(voltage, static_cast<double>(index));
    }
    return result;
}