#include <memory>
#include <iostream>
#include <string>

// C++ 11 version
template <typename T, typename U>
auto add1(T &&t, U &&u) -> decltype(std::forward<T>(t) + std::forward<U>(u))
{
    return std::forward<T>(t) + std::forward<U>(u);
};

// C++ 14 version
template <typename T, typename U>
decltype(auto) add(T &&t, U &&u)
{
    return std::forward<T>(t) + std::forward<U>(u);
};

template <typename T>
struct value_category
{
    // Or can be an integral or enum value
    static constexpr auto value = "prvalue";
};

template <typename T>
struct value_category<T &>
{
    static constexpr auto value = "lvalue";
};

template <typename T>
struct value_category<T &&>
{
    static constexpr auto value = "xvalue";
};

// Double parens for ensuring we inspect an expression,
// not an entity
#define VALUE_CATEGORY(expr) value_category<decltype((expr))>::value

#define PRINTTYPE(a)                                                   \
    std::cout << "Typename of " << #a << " is:" << typeid((a)).name(); \
    std::cout << ", value category is " << VALUE_CATEGORY(a) << std::endl;

using std::string;
int main(void)
{
    int a = 1;
    decltype(a) b = a;
    decltype((a)) c = a;
    b = 2;
    c = 3;
    PRINTTYPE(b);
    PRINTTYPE((b));

    {
        auto s = add(string("Hello"), string(" World"));
    }

    {
        auto s1 = string("Hello ");
        auto s2 = string(" World");
        auto ss = add(s1, s2);
    }
}