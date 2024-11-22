/////////////////////////////////////////////////////////////////
//
// <<一起来学C++ 29.函数封装与绑定>>视频配套例程
// function.cpp
// 函数封装示例
//
/////////////////////////////////////////////////////////////////

#include <functional>
#include <iostream>

double multiply(double a, double b)
{
    return a*b;
};

int main(void)
{
    std::function<double(double,double)> func1= multiply;
    double res = func1(1.1,2.3);
    std::cout<<res<<std::endl;
    return 0;
}

