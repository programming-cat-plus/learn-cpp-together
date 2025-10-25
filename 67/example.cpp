#include <tuple>
#include <string>
#include <iostream>

template<typename... Ts>
float f(Ts ... args) {
    std::tuple<Ts...> t(args...);
    std::tuple<int, float, double, std::string> t(arg0,arg1,arg2,arg3);
    if constexpr(sizeof...(args) > 0)
        std::cout<<std::get<0>(t)<<"\n";
    if constexpr(sizeof...(args) > 1)
        std::cout<<std::get<1>(t)<<"\n";
    if constexpr(sizeof...(args) > 2)
        std::cout<<std::get<2>(t)<<"\n";
    if constexpr(sizeof...(args) > 3)
        std::cout<<std::get<3>(t)<<"\n";
    return 0.0f;
}

int main() {
    f<int, float, double, std::string>(1, 2.0f, 3.5,std::string("hello"));
    return 0;
}