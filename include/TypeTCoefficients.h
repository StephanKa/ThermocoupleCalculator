#pragma once
#include <VoltageTemperatureConversion.h>
#include <array>

struct TypeT
{
    static constexpr std::string_view name = "TypeT";
    struct [[maybe_unused]] TemperatureToVoltage
    {
        struct Positive
        {
            static constexpr double lowerLimit = 0.0;
            static constexpr double upperLimit = 400.0;
            static constexpr std::array<double, 9> coefficient = {0.000000000000E+00,
                                                                  0.387481063640E-01,
                                                                  0.332922278800E-04,
                                                                  0.206182434040E-06,
                                                                  -0.218822568460E-08,
                                                                  0.109968809280E-10,
                                                                  -0.308157587720E-13,
                                                                  0.454791352900E-16,
                                                                  -0.275129016730E-19};
        };

        struct Negative
        {
            static constexpr double lowerLimit = -270.0;
            static constexpr double upperLimit = 0.0;
            static constexpr std::array<double, 15> coefficient = {0.000000000000E+00,
                                                                   0.387481063640E-01,
                                                                   0.441944343470E-04,
                                                                   0.118443231050E-06,
                                                                   0.200329735540E-07,
                                                                   0.901380195590E-09,
                                                                   0.226511565930E-10,
                                                                   0.360711542050E-12,
                                                                   0.384939398830E-14,
                                                                   0.282135219250E-16,
                                                                   0.142515947790E-18,
                                                                   0.487686622860E-21,
                                                                   0.107955392700E-23,
                                                                   0.139450270620E-26,
                                                                   0.797951539270E-30};
        };
    };

    struct [[maybe_unused]] VoltageToTemperature
    {
        struct Negative
        {
            static constexpr double lowerLimit = -5.603;
            static constexpr double upperLimit = 0.0;
            static constexpr double range = 0.04;
            static constexpr double error = -0.02;
            static constexpr std::array<double, 8> coefficient = {
                0.0000000E+00, 2.5949192E+01, -2.1316967E-01, 7.9018692E-01, 4.2527777E-01, 1.3304473E-01, 2.0241446E-02, 1.2668171E-03};
        };

        struct Positive
        {
            static constexpr double lowerLimit = 0.0;
            static constexpr double upperLimit = 20.872;
            static constexpr double range = 0.03;
            static constexpr double error = -0.03;
            static constexpr std::array<double, 8> coefficient = {
                0.000000E+00, 2.592800E+01, -7.602961E-01, 4.637791E-02, -2.165394E-03, 6.048144E-05, -7.293422E-07, 0.000000E+00};
        };
    };
};
