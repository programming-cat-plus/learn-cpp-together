#include <type_traits>
#include <iostream>
#include <vector>

template<typename T>
concept Arithmetic = std::is_arithmetic_v<T>;

template<Arithmetic... Args>
void f(Args ... args) {
    std::vector<double> t{double(args)...};
    for(auto v:t)
        std::cout<<v<<"\n";
}

int main() {
    f(1, 2.0f, 3.5,4);
    f(1, 2.0f, "string", 4); // This line would cause a compilation error
    return 0;
}