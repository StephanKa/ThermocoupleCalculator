#pragma once
#include <VoltageTemperatureConversion.h>
#include <array>

struct TypeJ
{
    struct [[maybe_unused]] TemperatureToVoltage
    {
        struct Positive
        {
            static constexpr double lowerLimit = 760.0;
            static constexpr double upperLimit = 1200.0;
            static constexpr std::array<double, 6> coefficient = {
                0.296456256810E+03, -0.149761277860E+01, 0.317871039240E-02, -0.318476867010E-05, 0.157208190040E-08, -0.306913690560E-12};
        };

        struct Negative
        {
            static constexpr double lowerLimit = -270.0;
            static constexpr double upperLimit = 760.0;
            static constexpr std::array<double, 9> coefficient = {0.000000000000E+00,
                                                                  0.503811878150E-01,
                                                                  0.304758369300E-04,
                                                                  -0.856810657200E-07,
                                                                  0.132281952950E-09,
                                                                  -0.170529583370E-12,
                                                                  0.209480906970E-15,
                                                                  -0.125383953360E-18,
                                                                  0.156317256970E-22};
        };
    };

    struct [[maybe_unused]] VoltageToTemperature
    {
        struct Negative
        {
            static constexpr double lowerLimit = -8.095;
            static constexpr double upperLimit = 0.0;
            static constexpr double range = 0.03;
            static constexpr double error = -0.05;
            static constexpr std::array<double, 9> coefficient = {
                0.0000000E+00, 1.9528268E+01, -1.2286185E+00, -1.0752178E+00, -5.9086933E-01, -1.7256713E-01, -2.8131513E-02, -2.3963370E-03, -8.3823321E-05};
        };

        struct Positive
        {
            static constexpr double lowerLimit = 0.0;
            static constexpr double upperLimit = 42.919;
            static constexpr double range = 0.04;
            static constexpr double error = -0.04;
            static constexpr std::array<double, 9> coefficient = {
                0.000000E+00, 1.978425E+01, -2.001204E-01, 1.036969E-02, -2.549687E-04, 3.585153E-06, -5.344285E-08, 5.099890E-10, 0.000000E+00};
        };
    };
};
