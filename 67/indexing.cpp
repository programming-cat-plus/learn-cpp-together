#include <iostream>
#include <tuple>
#include <utility>

template<std::size_t I, typename T,typename... Args>
auto element_at(T arg0, const Args &...args)
{
    static_assert(I < 1+sizeof...(Args), "Index out of bounds");
    if constexpr(I == 0)
        return arg0;
    else
        return element_at<I-1>(args...);
}

template<std::size_t I, typename... Args>
auto element_at_1(const Args &...args)
{
    static_assert(I < sizeof...(Args), "Index out of bounds");
    return std::get<I>(std::forward_as_tuple(args...));
}

template<std::size_t I, typename... Args>
auto element_at_1(const Args &...args)
{
    return args[I]...;
}

int main()
{
    std::cout << element_at<3>(1, 2.0, 'c', "string") << "\n";
    return 0;
}