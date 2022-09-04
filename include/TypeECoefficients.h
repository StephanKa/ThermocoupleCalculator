#pragma once
#include <VoltageTemperatureConversion.h>
#include <array>

struct TypeE
{
    static constexpr std::string_view NAME = "TypeE";
    struct [[maybe_unused]] TemperatureToVoltage
    {
        struct Positive
        {
            static constexpr double LOWER_LIMIT = 0.0;
            static constexpr double UPPER_LIMIT = 1000.0;
            static constexpr std::array COEFFICIENT = {0.000000000000E+00,
                                                       0.586655087100E-01,
                                                       0.450322755820E-04,
                                                       0.289084072120E-07,
                                                       -0.330568966520E-09,
                                                       0.650244032700E-12,
                                                       -0.191974955040E-15,
                                                       -0.125366004970E-17,
                                                       0.214892175690E-20,
                                                       -0.143880417820E-23,
                                                       0.359608994810E-27};
        };

        struct Negative
        {
            static constexpr double LOWER_LIMIT = -270.0;
            static constexpr double UPPER_LIMIT = 0.0;
            static constexpr std::array COEFFICIENT = {0.000000000000E+00,
                                                       0.586655087080E-01,
                                                       0.454109771240E-04,
                                                       -0.779980486860E-06,
                                                       -0.258001608430E-07,
                                                       -0.594525830570E-09,
                                                       -0.932140586670E-11,
                                                       -0.102876055340E-12,
                                                       -0.803701236210E-15,
                                                       -0.439794973910E-17,
                                                       -0.164147763550E-19,
                                                       -0.396736195160E-22,
                                                       -0.558273287210E-25,
                                                       -0.346578420130E-28};
        };
    };

    struct [[maybe_unused]] VoltageToTemperature
    {
        struct Negative
        {
            static constexpr double LOWER_LIMIT = -200.0;
            static constexpr double UPPER_LIMIT = 0.0;
            static constexpr double RANGE = 0.03;
            static constexpr double ERROR = -0.01;
            static constexpr std::array COEFFICIENT = {
                0.0000000E+00, 1.6977288E+01, -4.3514970E-01, -1.5859697E-01, -9.2502871E-02, -2.6084314E-02, -4.1360199E-03, -3.4034030E-04, -1.1564890E-05, 0.0000000E+00};
        };

        struct Positive
        {
            static constexpr double LOWER_LIMIT = 0.0;
            static constexpr double UPPER_LIMIT = 1000.0;
            static constexpr double RANGE = 0.02;
            static constexpr double ERROR = -0.02;
            static constexpr std::array COEFFICIENT = {
                0.0000000E+00, 1.7057035E+01, -2.3301759E-01, 6.5435585E-03, -7.3562749E-05, -1.7896001E-06, 8.4036165E-08, -1.3735879E-09, 1.0629823E-11, -3.2447087E-14};
        };
    };
};
