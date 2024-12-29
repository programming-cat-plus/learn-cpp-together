#include <array>
#include <cmath>

constexpr float ff(float a,float b)
{
    return powf(a,b);
}

constexpr int factorial(int n)
{
    if(n>1)
        return n * factorial(n - 1);

    return 1;
}

int main(void)
{
    {
        const int n = 10;
        char arr1[n] = {};
        std::array<char, n> arr2;
        enum
        {
            ONE,
            TWO,
            TEN = n
        };
    }
#if 0
    {
        int m = 10;
        const int n = m;
        char arr1[n] = {};
        std::array<char, n> arr2;
        enum
        {
            ONE,
            TWO,
            TEN = n
        };

        std::array<char, factorial(10)> arr3;
    }
#endif
    std::array<char, factorial(5)> arr3;
    int k = factorial(10);
    float s;
    s = ff(10,0.9);
}