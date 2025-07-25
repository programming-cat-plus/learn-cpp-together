#include <complex>
#include <iostream>
using namespace std::complex_literals;

int main() {
    std::complex<double> c1 = 3.0 + 4.0i; // 3 + 4i
    std::complex<double> c2 = 5.0 - 2.0i; // 5 - 2i

    std::cout << "c1: " << c1 << "\n";
    std::cout << "c2: " << c2 << "\n";

    auto sum = c1 + c2;
    auto diff = c1 - c2;

    std::cout << "Sum: " << sum << "\n";
    std::cout << "Difference: " << diff << "\n";

    std::cout<< 4.0i .imag() << "\n"; // Output the imaginary part of 4.0i

    return 0;
}


