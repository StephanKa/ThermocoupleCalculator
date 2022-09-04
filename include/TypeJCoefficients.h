#pragma once
#include <VoltageTemperatureConversion.h>
#include <array>

struct TypeJ
{
    static constexpr std::string_view NAME = "TypeJ";
    struct [[maybe_unused]] TemperatureToVoltage
    {
        struct Positive
        {
            static constexpr double LOWER_LIMIT = 760.0;
            static constexpr double UPPER_LIMIT = 1200.0;
            static constexpr std::array COEFFICIENT = {0.296456256810E+03, -0.149761277860E+01, 0.317871039240E-02, -0.318476867010E-05, 0.157208190040E-08, -0.306913690560E-12};
        };

        struct Negative
        {
            static constexpr double LOWER_LIMIT = -270.0;
            static constexpr double UPPER_LIMIT = 760.0;
            static constexpr std::array COEFFICIENT = {0.000000000000E+00,
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
            static constexpr double LOWER_LIMIT = -8.095;
            static constexpr double UPPER_LIMIT = 0.0;
            static constexpr double RANGE = 0.03;
            static constexpr double ERROR = -0.05;
            static constexpr std::array COEFFICIENT = {
                0.0000000E+00, 1.9528268E+01, -1.2286185E+00, -1.0752178E+00, -5.9086933E-01, -1.7256713E-01, -2.8131513E-02, -2.3963370E-03, -8.3823321E-05};
        };

        struct Positive
        {
            static constexpr double LOWER_LIMIT = 0.0;
            static constexpr double UPPER_LIMIT = 42.919;
            static constexpr double RANGE = 0.04;
            static constexpr double ERROR = -0.04;
            static constexpr std::array COEFFICIENT = {
                0.000000E+00, 1.978425E+01, -2.001204E-01, 1.036969E-02, -2.549687E-04, 3.585153E-06, -5.344285E-08, 5.099890E-10, 0.000000E+00};
        };
    };
};
