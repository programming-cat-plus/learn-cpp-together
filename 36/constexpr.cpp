#include <array>
constexpr int multiply(int a, int b)
{
    return a * b;
}

int main(void)
{

    {
        constexpr int a{12};
    }
    
    {
        const int a{12};
        constexpr int b{a+3};
    }

    {
        const float a{12};
        //constexpr float b{a+3};
    }

    {
        constexpr float a{12};
        constexpr float b{a+3};
    }

    {
        constexpr int c = multiply(5, 3);
        int d = multiply(c, 11);
        int f = multiply(d, 7);
    }
    {
        int s = 13 * 13 + 2;
        const float s2{10.5};

        int *p = const_cast<int *>(&s);
        *p = 11;

        float *p2 = const_cast<float *>(&s2);
        *p2 = 13.2;
    }

    {
        constexpr auto nn = 3 * 3;
        std::array<float, nn> myarray;
    }
}