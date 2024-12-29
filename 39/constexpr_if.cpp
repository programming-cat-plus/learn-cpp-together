#include <cmath>
#include <type_traits>
#include <iostream>
#include <vector>

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

template <typename T>
double length(T &t)
{
    static_assert(std::is_arithmetic_v<T> || std::is_base_of_v<IMeasurable, T>, "错误：使用了不支持计算长度的类型");

    if constexpr (std::is_arithmetic_v<T>)
    {
        if (t < 0)
            return -t;
        return t;
    }
    else if constexpr (std::is_base_of_v<IMeasurable, T>)
        return t.length();
}

int main()
{
    double l = -13.5;
    std::cout << length(l) << "\n";

    Complex v = {1.5, 3.0};
    std::cout << length(v) << "\n";

    //std::vector<int> numbers{1, 3, 4};
    //std::cout<<length(numbers)<<"\n";

}