#pragma once
#include <cmath>
#include <string_view>

namespace Helper
{
    enum class Conversion
    {
        Volt,
        Temp
    };

    template <typename T>
    class NamedType
    {
    public:
        using Type = T;
        constexpr NamedType() = default;
#if defined(__GNUC__) || defined(__GNUG__)// WORKAROUND for GCC bug https://gcc.gnu.org/bugzilla/show_bug.cgi?id=104490
        constexpr explicit NamedType(const T& value) : m_value(value)
        {
        }

        constexpr explicit NamedType(T&& value) : m_value(std::move(value))
        {
        }
#else
    consteval explicit NamedType(const T &value) : m_value(value)
    {}
    consteval explicit NamedType(T &&value) : m_value(std::move(value))
    {}
#endif
        consteval NamedType& operator=(T value)
        {
            m_value = value;
            return *this;
        }

        constexpr T operator()() const
        {
            return m_value;
        }

    private:
        const T m_value{};
    };

    namespace Math
    {
        [[nodiscard]] constexpr double pow(double x, int y)
        {
            return y == 0 ? 1.0 : x * pow(x, y - 1);
        }

        [[nodiscard]] constexpr int factorial(int x)
        {
            return x == 0 ? 1 : x * factorial(x - 1);
        }

        [[nodiscard]] constexpr double exp(double x)
        {
            constexpr int maxFactor = 10;
            double val = 1.0 + x;
            for (int i = 2; i < maxFactor; ++i)
            {
                val += pow(x, i) / factorial(i);
            }
            return val;
        }
    } // namespace Math
} // namespace Helper

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

template <typename T, Helper::Conversion TargetConversion>
[[nodiscard]] constexpr auto calculation(const T& coefficient, const auto& value)
{
    double result = 0.0;
    size_t index = 0;
    if constexpr (TargetConversion == Helper::Conversion::Temp)
    {
        result = coefficient[index];
        index = 1;
    }
    for (; index < coefficient.size(); index++)
    {
        result += coefficient.at(index) * Helper::Math::pow(value(), static_cast<int>(index));
    }
    return result;
}

template <class TypeConversion, Helper::Conversion Type>
[[nodiscard]] constexpr auto conversion(const auto& value)
{
    using NEGATIVE = typename TypeConversion::Negative;
    using POSITIVE = typename TypeConversion::Positive;

    if (value() >= NEGATIVE::LIMITS.LOWER && value() <= NEGATIVE::LIMITS.UPPER)
    {
        return calculation<decltype(NEGATIVE::COEFFICIENT), Type>(NEGATIVE::COEFFICIENT, value);
    }
    if (value() >= POSITIVE::LIMITS.LOWER && value() <= POSITIVE::LIMITS.UPPER)
    {
        return calculation<decltype(POSITIVE::COEFFICIENT), Type>(POSITIVE::COEFFICIENT, value);
    }
    return std::numeric_limits<typename std::remove_cvref_t<decltype(value)>::Type>::max();
}
