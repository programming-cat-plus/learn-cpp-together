#include <iostream>
#include <concepts>
#include <type_traits>

template<class T> 
concept Arithmetic = std::is_arithmetic_v<T>;

Arithmetic auto add(Arithmetic auto a,Arithmetic auto b){
    return a + b;
};


int main() {
    std::cout << "Sum of 10 and 20 is: " << add(10, 20) << std::endl;
    std::cout << "Sum of 5.5 and 3.2 is: " << add(5.5, 3.2) << std::endl;
    std::cout << "Sum of 5.1 and 2 is: " << add(5.1, 2) << std::endl;
    std::cout << "Sum of 'apple' and 'banana' is: " << add(std::string("apple"), std::string("banana")) << std::endl;
    return 0;
}




