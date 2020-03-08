#pragma once
#include <array>

struct TypeR
{
    struct TemperatureToVoltage
    {
        struct Positive
        {
            static constexpr double lowerLimit = 1064.18;
            static constexpr double upperLimit = 1664.5;
            static constexpr std::array<double, 6> coefficient = {
                0.295157925316E+01, -0.252061251332E-02, 0.159564501865E-04, -0.764085947576E-08, 0.205305291024E-11, -0.293359668173E-15};
        };

        struct Negative
        {
            static constexpr double lowerLimit = -50.0;
            static constexpr double upperLimit = 1064.18;
            static constexpr std::array<double, 10> coefficient = {0.000000000000E+00, 0.528961729765E-02, 0.139166589782E-04, -0.238855693017E-07,
                0.356916001063E-10, -0.462347666298E-13, 0.500777441034E-16, -0.373105886191E-19, 0.157716482367E-22, -0.281038625251E-26};
        };
    };

    struct VoltageToTemperature
    {
        struct Negative
        {
            static constexpr double lowerLimit = -0.226;
            static constexpr double upperLimit = 1.923;
            static constexpr double range = 0.02;
            static constexpr double error = -0.02;
            static constexpr std::array<double, 11> coefficient = {0.0000000E+00, 1.8891380E+02, -9.3835290E+01, 1.3068619E+02, -2.2703580E+02, 3.5145659E+02,
                -3.8953900E+02, 2.8239471E+02, -1.2607281E+02, 3.1353611E+01, -3.3187769E+00};
        };

        struct Positive
        {
            static constexpr double lowerLimit = 1.923;
            static constexpr double upperLimit = 13.228;
            static constexpr double range = 0.005;
            static constexpr double error = -0.005;
            static constexpr std::array<double, 11> coefficient = {1.334584505E+01, 1.472644573E+02, -1.844024844E+01, 4.031129726E+00, -6.249428360E-01,
                6.468412046E-02, -4.458750426E-03, 1.994710149E-04, -5.313401790E-06, 6.481976217E-08, 0.000000000E+00};
        };
    };
};
