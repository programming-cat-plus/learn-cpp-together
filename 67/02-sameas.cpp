#include <iostream>
#include <concepts>

template<std::same_as<int>...T>
int sum(T...args) {
    auto s = (args + ... + 0);
    std::cout << s << std::endl;
    return s;
}

int main() {
    sum(1, 2, 3, 4, std::string{"15"});
    return 0;
}