#pragma once
#include "VoltageTemperatureConversion.h"

#include <array>

struct TypeS
{
    static constexpr std::string_view NAME = "TypeS";
    struct [[maybe_unused]] TemperatureToVoltage
    {
        struct Positive
        {
            static constexpr Limits LIMITS{ 1064.18, 1664.5 };
            // clang-format off
            static constexpr std::array COEFFICIENT = { 0.132900444085E+01,
                                                        0.334509311344E-02,
                                                        0.654805192818E-05,
                                                       -0.164856259209E-08,
                                                        0.129989605174E-13};
            // clang-format on
        };

        struct Negative
        {
            static constexpr Limits LIMITS{ -50.0, 1064.18 };
            // clang-format off
            static constexpr std::array COEFFICIENT = {0.000000000000E+00,
                                                       0.540313308631E-02,
                                                       0.125934289740E-04,
                                                       -0.232477968689E-07,
                                                       0.322028823036E-10,
                                                       -0.331465196389E-13,
                                                       0.255744251786E-16,
                                                       -0.125068871393E-19,
                                                       0.271443176145E-23};
            // clang-format on
        };
    };

    struct [[maybe_unused]] VoltageToTemperature
    {
        struct Negative
        {
            static constexpr Limits LIMITS{ -0.235, 1.874 };
            static constexpr double RANGE = 0.02;
            static constexpr double ERROR = -0.02;
            // clang-format off
            static constexpr std::array COEFFICIENT = { 0.00000000E+00,
                                                        1.84949460E+02,
                                                       -8.00504062E+01,
                                                        1.02237430E+02,
                                                       -1.52248592E+02,
                                                        1.88821343E+02,
                                                       -1.59085941E+02,
                                                        8.23027880E+01,
                                                       -2.34181944E+01,
                                                        2.79786260E+00};
            // clang-format on
        };

        struct Positive
        {
            static constexpr Limits LIMITS{ 1.874, 11.950 };
            static constexpr double RANGE = 0.01;
            static constexpr double ERROR = -0.01;
            // clang-format off
            static constexpr std::array COEFFICIENT = {1.291507177E+01,
                                                       1.466298863E+02,
                                                       -1.534713402E+01,
                                                       3.145945973E+00,
                                                       -4.163257839E-01,
                                                       3.187963771E-02,
                                                       -1.291637500E-03,
                                                       2.183475087E-05,
                                                       -1.447379511E-07,
                                                       8.211272125E-09};
            // clang-format on
        };
    };
};
