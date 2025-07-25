#include <iostream>

template<char... t>
constexpr auto operator""_b() {
    long res = 0;
    for(auto c:{t...})
    {
        std::cout << c;
        if(c == '1')
            res = (res << 1) | 1;
        else if(c == '0')
            res = res << 1;
        else
            throw std::invalid_argument("Invalid binary digit");
    }
    return res;
}

int main() {
    auto bin = 1001_b;
    std::cout<< "Binary to decimal: " << bin << std::endl;
    return 0;
}