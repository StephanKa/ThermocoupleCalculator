#pragma once
#include "VoltageTemperatureConversion.h"

#include <array>

struct TypeB
{
    static constexpr std::string_view NAME = "TypeB";
    struct [[maybe_unused]] TemperatureToVoltage
    {
        static constexpr Limits LIMITS{ 0.0, 700.0 };
        // clang-format off
        static constexpr std::array COEFFICIENT = { 0.000000000000E+00,
                                                   -0.246508183460E-03,
                                                    0.590404211710E-05,
                                                   -0.132579316360E-08,
                                                    0.156682919010E-11,
                                                   -0.169445292400E-14,
                                                    0.629903470940E-18};
        // clang-format on

        [[nodiscard]] static constexpr auto calculate(const auto &degrees)
        {
            if (degrees() >= LIMITS.LOWER && degrees() <= LIMITS.UPPER) {
                return calculation<decltype(COEFFICIENT), Helper::Conversion::Volt>(COEFFICIENT, degrees);
            }
            return std::numeric_limits<double>::max();
        }
    };

    struct [[maybe_unused]] VoltageToTemperature
    {
        static constexpr Limits LIMITS{ 0.291, 2.431 };
        static constexpr double RANGE = 0.03;
        static constexpr double ERROR = -0.02;
        // clang-format off
        static constexpr std::array COEFFICIENT = { 9.8423321E+01,
                                                    6.9971500E+02,
                                                   -8.4765304E+02,
                                                    1.0052644E+03,
                                                   -8.3345952E+02,
                                                    4.5508542E+02,
                                                   -1.5523037E+02,
                                                    2.9886750E+01,
                                                   -2.4742860E+00};
        // clang-format on

        [[nodiscard]] static constexpr auto calculate(const auto &voltage)
        {
            if (voltage() >= LIMITS.LOWER && voltage() <= LIMITS.UPPER) {
                return calculation<decltype(COEFFICIENT), Helper::Conversion::Temp>(COEFFICIENT, voltage);
            }
            return std::numeric_limits<double>::max();
        }
    };
};
