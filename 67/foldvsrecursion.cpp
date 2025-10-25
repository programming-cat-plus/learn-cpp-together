#include <concepts>
#include <iostream>
template <typename... Ts>
void print_fold(Ts... args)
{
    ((std::cout << args << "\n"), ...);
}

void print_recursion(const auto &first, const auto &...rest)
{
    std::cout << first << "\n";
    if constexpr(sizeof...(rest) > 0)
    {       
        print_recursion(rest...);
    }    
}

int main()
{
    print_fold(1, 2.0, 'c', "string");
    print_recursion(1, 2.0, 'c', "string");
    return 0;
}