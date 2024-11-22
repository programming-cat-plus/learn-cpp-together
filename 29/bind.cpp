/////////////////////////////////////////////////////////////////
//
// <<一起来学C++ 29.函数封装与绑定>>视频配套例程
// bind.cpp
// 绑定bind示例
//
/////////////////////////////////////////////////////////////////

#include <functional>
#include <iostream>

using namespace std::placeholders;

int sum(int a, int b, int c)
{
    std::cout << "a=" << a << ", b=" << b << ", c=" << c;
    return a + b + c;
}

int main(void)
{
    {
        auto f = std::bind(sum, 1, 2, 3);
        int res = f();
        std::cout << ", res=" << res << std::endl;
    }

    {
        int n = 6;
        auto f = std::bind(sum, 1, 2, std::cref(n));
        n = 11;
        int res = f();
        std::cout << ", res=" << res << std::endl;
    }

    {
        auto f = std::bind(sum, 1, _1, 3);
        int res = f(5);
        std::cout << ", res=" << res << std::endl;
    }
}