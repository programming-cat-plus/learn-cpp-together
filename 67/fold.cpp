#include <iostream>
#include <concepts>

template<std::convertible_to<double>...T>
auto binary_left(T...args) {
    return (0 + ... + (args*args));
}

template<std::convertible_to<double>...T>
auto unary_left(T...args) {
    return ( ... + (args*args));
}


int main() {
    std::cout << binary_left(1.0, 2.0, 3.0, 4.0, 5.0) << std::endl; 
    std::cout << unary_left(1.0, 2.0, 3.0, 4.0, 5.0) << std::endl;
    return 0;
}