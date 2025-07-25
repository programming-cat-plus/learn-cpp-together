#include <complex>
#include <iostream>

constexpr std::complex<double> operator""_i(long double imag) {
    return std::complex<double>(0.0, imag);
}

int main() {
    std::complex<double> c1 = 3.0 + 4.0_i; // 3 + 4i
    std::complex<double> c2 = 5.0 - 2.0_i; // 5 - 2i

    std::cout << "c1: " << c1 << "\n";
    std::cout << "c2: " << c2 << "\n";

    auto sum = c1 + c2;
    auto diff = c1 - c2;

    std::cout << "Sum: " << sum << "\n";
    std::cout << "Difference: " << diff << "\n";
    std::cout << 4.0_i .imag() << "\n"; 
    return 0;
}


