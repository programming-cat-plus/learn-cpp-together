#include <tuple>
#include <iostream>
#include <concepts>

template<typename T1, typename...T2>
void f(T1 a, T2...b) {
    std::tuple<T1, T2...> t(a, b...);
    return;
}

template<std::same_as<int>...T>
int sum(T...args) {
    auto s = (args + ... + 0);
    std::cout << s << std::endl;
    return s;
}

template<typename T1, typename...T2>
void print(T1 a, T2... args) {
    std::cout<< a << std::endl;
    if constexpr (sizeof...(args) > 0) {
        print(args...);
    }
}

int main() {
    print(1, 2.0, 'c', "string");
    sum(1, 2, 3, 4, 5);
    return 0;
}