#pragma once
#include <cmath>
#include <string_view>

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
    constexpr explicit NamedType(const T& value) : m_value(value) {}
    constexpr explicit NamedType(T&& value) : m_value(std::move(value)) {}

    constexpr NamedType& operator=(T value)
    {
        m_value = value;
        return *this;
    }
    constexpr T operator()() const { return m_value; }

private:
    const T m_value{};
};

struct Temperature : NamedType<double>
{
    using NamedType::NamedType;
};

struct Voltage : NamedType<double>
{
    using NamedType::NamedType;
};

namespace Math {
constexpr double pow(double x, int y) { return y == 0 ? 1.0 : x * pow(x, y - 1); }
constexpr int factorial(int x) { return x == 0 ? 1 : x * factorial(x - 1); }
}  // namespace Math

struct Limits
{
    double LOWER;
    double UPPER;
};

template<typename T, Conversion TargetConversion>
constexpr auto calculation(const T& coefficient, const auto& value) -> double
{
    double result = 0.0;
    size_t index = 0;
    if constexpr (TargetConversion == Conversion::Temp)
    {
        result = coefficient[0];
        index = 1;
    }
    for (; index < coefficient.size(); index++)
    {
        result += coefficient.at(index) * Math::pow(value(), static_cast<int>(index));
    }
    return result;
}

template<class Positive, class Negative, Conversion Type>
constexpr auto conversion(const auto& value) -> double
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
