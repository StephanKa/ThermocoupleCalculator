#pragma once
#include <VoltageTemperatureConversion.h>
#include <array>

struct TypeN
{
    static constexpr std::string_view NAME = "TypeN";
    struct [[maybe_unused]] TemperatureToVoltage
    {
        struct Positive
        {
            static constexpr double LOWER_LIMIT = 0.0;
            static constexpr double UPPER_LIMIT = 1300.0;
            static constexpr std::array COEFFICIENT = {0.000000000000E+00,
                                                       0.259293946010E-01,
                                                       0.157101418800E-04,
                                                       0.438256272370E-07,
                                                       -0.252611697940E-09,
                                                       0.643118193390E-12,
                                                       -0.100634715190E-14,
                                                       0.997453389920E-18,
                                                       -0.608632456070E-21,
                                                       0.208492293390E-24,
                                                       -0.306821961510E-28};
        };

        struct Negative
        {
            static constexpr double LOWER_LIMIT = -270.0;
            static constexpr double UPPER_LIMIT = 0.0;
            static constexpr std::array COEFFICIENT = {0.000000000000E+00,
                                                       0.261591059620E-01,
                                                       0.109574842280E-04,
                                                       -0.938411115540E-07,
                                                       -0.464120397590E-10,
                                                       -0.263033577160E-11,
                                                       -0.226534380030E-13,
                                                       -0.760893007910E-16,
                                                       -0.934196678350E-19};
        };
    };

    struct [[maybe_unused]] VoltageToTemperature
    {
        struct Negative
        {
            static constexpr double LOWER_LIMIT = -3.99;
            static constexpr double UPPER_LIMIT = 0.0;
            static constexpr double RANGE = 0.03;
            static constexpr double ERROR = -0.02;
            static constexpr std::array COEFFICIENT = {
                0.0000000E+00, 3.8436847E+01, 1.1010485E+00, 5.2229312E+00, 7.2060525E+00, 5.8488586E+00, 2.7754916E+00, 7.7075166E-01, 1.1582665E-01, 7.3138868E-03};
        };

        struct Positive
        {
            static constexpr double LOWER_LIMIT = 0.0;
            static constexpr double UPPER_LIMIT = 20.613;
            static constexpr double RANGE = 0.03;
            static constexpr double ERROR = -0.02;
            static constexpr std::array COEFFICIENT = {
                0.00000E+00, 3.86896E+01, -1.08267E+00, 4.70205E-02, -2.12169E-06, -1.17272E-04, 5.39280E-06, -7.98156E-08, 0.00000E+00, 0.00000E+00};
        };
    };
};
