#include <cmath>
#include <type_traits>
#include <iostream>
#include <vector>
#include <tuple>

class IMeasurable
{
public:
    virtual double length() = 0;
};

class Complex : public IMeasurable
{
public:
    Complex(double r, double i) : imaginary(i), real(r) {};
    double length() override { return std::sqrt(imaginary * imaginary + real * real); }
private:
    double imaginary = 0;
    double real = 0;
};

template<typename T> concept  Measurable = std::is_arithmetic_v<T>||requires(T t)
{
    t.length();
};

template <Measurable T>
double length(T &t)
{
    if constexpr (std::is_arithmetic_v<T>)
    {
        if (t < 0)
            return -t;
        return t;
    }
    else
        return t.length();
}

int main()
{
    auto values = std::make_tuple(1, 2, 3,Complex(12,34),"1234");
}