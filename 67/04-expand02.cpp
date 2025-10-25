#include <tuple>
#include <string>
#include <iostream>
#include <vector>
#include <concepts>

template<std::convertible_to<double>... Ts>
void f(Ts ... args) {
    std::vector<double> t{1.0+(args)*(args)...};
    for(auto v:t)
        std::cout<<v<<"\n";

    std::cout<<"size of pack:"<<sizeof...(args)<<"\n";
}

int main() {
    f(1, 2.0f, 3.5,4);
    return 0;
}