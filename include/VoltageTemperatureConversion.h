#pragma once
#include <cmath>
#include <string_view>

namespace Helper {
enum class Conversion
{
    Volt,
    Temp
};

template<typename T>
class NamedType
{
public:
    using Type = T;
    NamedType() = default;
    consteval explicit NamedType(const T& value) : m_value(value) {}
    consteval explicit NamedType(T&& value) : m_value(std::move(value)) {}

    consteval NamedType& operator=(T value)
    {
        m_value = value;
        return *this;
    }
    consteval T operator()() const { return m_value; }

private:
    const T m_value{};
};

namespace Math {
consteval double pow(double x, int y) { return y == 0 ? 1.0 : x * pow(x, y - 1); }
consteval int factorial(int x) { return x == 0 ? 1 : x * factorial(x - 1); }

consteval double exp(double x)
{
    return 1.0 + x + pow(x, 2) / factorial(2) + pow(x, 3) / factorial(3) + pow(x, 4) / factorial(4) + pow(x, 5) / factorial(5) + pow(x, 6) / factorial(6) + pow(x, 7) / factorial(7)
           + pow(x, 8) / factorial(8) + pow(x, 9) / factorial(9);
}
}  // namespace Math

}  // namespace Helper

struct Temperature : Helper::NamedType<double>
{
    using NamedType::NamedType;
};

struct Voltage : Helper::NamedType<double>
{
    using NamedType::NamedType;
};

struct Limits
{
    double LOWER;
    double UPPER;
};

template<typename T, Helper::Conversion TargetConversion>
consteval auto calculation(const T& coefficient, const auto& value)
{
    double result = 0.0;
    size_t index = 0;
    if constexpr (TargetConversion == Helper::Conversion::Temp)
    {
        result = coefficient[0];
        index = 1;
    }
    for (; index < coefficient.size(); index++)
    {
        result += coefficient.at(index) * Helper::Math::pow(value(), static_cast<int>(index));
    }
    return result;
}

template<class Positive, class Negative, Helper::Conversion Type>
consteval auto conversion(const auto& value)
{
    if (value() >= Negative::LIMITS.LOWER && value() <= Negative::LIMITS.UPPER)
    {
        return calculation<decltype(Negative::COEFFICIENT), Type>(Negative::COEFFICIENT, value);
    }
    if (value() >= Positive::LIMITS.LOWER && value() <= Positive::LIMITS.UPPER)
    {
        return calculation<decltype(Positive::COEFFICIENT), Type>(Positive::COEFFICIENT, value);
    }
    return std::numeric_limits<typename std::remove_cvref_t<decltype(value)>::Type>::max();
}
