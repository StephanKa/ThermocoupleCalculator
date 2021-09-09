#pragma once
#include "VoltageTemperatureConversion.h"

#include <array>

struct TypeB
{
    struct [[maybe_unused]] TemperatureToVoltage
    {
        static constexpr double lowerLimit = 0.0;
        static constexpr double upperLimit = 700.0;
        static constexpr std::array<double, 7> coefficient = {
            0.000000000000E+00, -0.246508183460E-03, 0.590404211710E-05, -0.132579316360E-08, 0.156682919010E-11, -0.169445292400E-14, 0.629903470940E-18};

        static constexpr auto calculate(double const degrees) -> double
        {
            if (degrees >= lowerLimit && degrees <= upperLimit)
            {
                return calculation<decltype(coefficient), Conversion::Voltage>(coefficient, degrees);
            }
            return 0.0;
        }
    };

    struct [[maybe_unused]] VoltageToTemperature
    {
        static constexpr double lowerLimit = 0.291;
        static constexpr double upperLimit = 2.431;
        static constexpr double range = 0.03;
        static constexpr double error = -0.02;
        static constexpr std::array<double, 9> coefficient = {
            9.8423321E+01, 6.9971500E+02, -8.4765304E+02, 1.0052644E+03, -8.3345952E+02, 4.5508542E+02, -1.5523037E+02, 2.9886750E+01, -2.4742860E+00};

        static constexpr auto calculate(double const voltage) -> double
        {
            if (voltage >= lowerLimit && voltage <= upperLimit)
            {
                return calculation<decltype(coefficient), Conversion::Temperature>(coefficient, voltage);
            }
            return 0.0;
        }
    };
};
