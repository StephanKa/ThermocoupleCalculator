#pragma once
#include <array>
#include <cmath>

struct TypeK
{
    struct TemperatureToVoltage
    {
        struct Positive
        {
            static constexpr double lowerLimit = 0.0;
            static constexpr double upperLimit = 1372.0;
            static constexpr std::array<double, 10> coefficient = {-0.176004136860e-01, 0.389212049750e-01, 0.185587700320e-04, -0.994575928740e-07,
                0.318409457190e-09, -0.560728448890e-12, 0.560750590590e-15, -0.320207200030e-18, 0.971511471520e-22, -0.121047212750e-25};
            static constexpr std::array<double, 3> alphaCoefficient = {0.118597600000e0, -0.118343200000e-3, 0.1269686e3};
        };

        struct Negative
        {
            static constexpr double lowerLimit = -270.0;
            static constexpr double upperLimit = 0.0;
            static constexpr std::array<double, 11> coefficient = {0.000000000000e+00, 0.394501280250e-01, 0.236223735980e-04, -0.328589067840e-06,
                -0.499048287770e-08, -0.675090591730e-10, -0.574103274280e-12, -0.310888728940e-14, -0.104516093650e-16, -0.198892668780e-19,
                -0.163226974860e-22};
        };

        static constexpr auto calculate = [](double& ret, double const value) {
            ret = Positive::coefficient[0];
            for (int index = 1; index < static_cast<int>(Positive::coefficient.size()); index++)
            {
                ret += Positive::coefficient.at(index) * std::pow(value, static_cast<double>(index));
            }
            ret += Positive::alphaCoefficient.at(0) * std::exp(Positive::alphaCoefficient.at(1) * std::pow(value - Positive::alphaCoefficient.at(2), 2));
        };
    };

    struct VoltageToTemperature
    {
        struct Negative
        {
            static constexpr double lowerLimit = -5.891;
            static constexpr double upperLimit = 0.0;
            static constexpr double range = 0.04;
            static constexpr double error = -0.02;
            static constexpr std::array<double, 10> coefficient = {0.0000000E+00, 2.5173462E+01, -1.1662878E+00, -1.0833638E+00, -8.9773540E-01, -3.7342377E-01,
                -8.6632643E-02, -1.0450598E-02, -5.1920577E-04, 0.0000000E+00};
        };

        struct Positive
        {
            static constexpr double lowerLimit = 0.0;
            static constexpr double upperLimit = 20.644;
            static constexpr double range = 0.04;
            static constexpr double error = -0.05;
            static constexpr std::array<double, 10> coefficient = {
                0.000000E+00, 2.508355E+01, 7.860106E-02, -2.503131E-01, 8.315270E-02, -1.228034E-02, 9.804036E-04, -4.413030E-05, 1.057734E-06, -1.052755E-08};
        };
    };
};