#include <iostream>
constexpr long double operator""_m(long double x) { return x; }
constexpr long double operator""_dm(long double x) { return x * 0.1; }
constexpr long double operator""_cm(long double x) { return x * 0.01; }
constexpr long double operator""_nm(long double x) { return x * 1e-9; }
constexpr long double operator""_pm(long double x) { return x * 1e-12; }

int main()
{
    long double x = 1.0_m;
    long double y = 2.0_dm;
    long double z = 3.0_cm;
    long double w = 4.0_nm;
    long double v = 3.1415926_pm;

    std::cout << "x: " << x << ", y: " << y << ", z: " << z
              << ", w: " << w << ", v: " << v << std::endl;

    return 0;
}
