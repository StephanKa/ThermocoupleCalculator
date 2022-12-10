#pragma once
#include <VoltageTemperatureConversion.h>
#include <array>

struct TypeR
{
    static constexpr std::string_view NAME = "TypeR";
    struct [[maybe_unused]] TemperatureToVoltage
    {
        struct Positive
        {
            static constexpr Limits LIMITS{1064.18, 1664.5};
            // clang-format off
            static constexpr std::array COEFFICIENT = { 0.295157925316E+01,
                                                       -0.252061251332E-02,
                                                        0.159564501865E-04,
                                                       -0.764085947576E-08,
                                                        0.205305291024E-11,
                                                       -0.293359668173E-15};
            // clang-format on
        };

        struct Negative
        {
            static constexpr Limits LIMITS{-50.0, 1064.18};
            // clang-format off
            static constexpr std::array COEFFICIENT = {0.000000000000E+00,
                                                       0.528961729765E-02,
                                                       0.139166589782E-04,
                                                       -0.238855693017E-07,
                                                       0.356916001063E-10,
                                                       -0.462347666298E-13,
                                                       0.500777441034E-16,
                                                       -0.373105886191E-19,
                                                       0.157716482367E-22,
                                                       -0.281038625251E-26};
            // clang-format on
        };
    };

    struct [[maybe_unused]] VoltageToTemperature
    {
        struct Negative
        {
            static constexpr Limits LIMITS{-0.226, 1.923};
            static constexpr double RANGE = 0.02;
            static constexpr double ERROR = -0.02;
            // clang-format off
            static constexpr std::array COEFFICIENT = {0.0000000E+00,
                                                       1.8891380E+02,
                                                       -9.3835290E+01,
                                                       1.3068619E+02,
                                                       -2.2703580E+02,
                                                       3.5145659E+02,
                                                       -3.8953900E+02,
                                                       2.8239471E+02,
                                                       -1.2607281E+02,
                                                       3.1353611E+01,
                                                       -3.3187769E+00};
            // clang-format on
        };

        struct Positive
        {
            static constexpr Limits LIMITS{1.923, 13.228};
            static constexpr double RANGE = 0.005;
            static constexpr double ERROR = -0.005;
            // clang-format off
            static constexpr std::array COEFFICIENT = {1.334584505E+01,
                                                       1.472644573E+02,
                                                       -1.844024844E+01,
                                                       4.031129726E+00,
                                                       -6.249428360E-01,
                                                       6.468412046E-02,
                                                       -4.458750426E-03,
                                                       1.994710149E-04,
                                                       -5.313401790E-06,
                                                       6.481976217E-08,
                                                       0.000000000E+00};
            // clang-format on
        };
    };
};
