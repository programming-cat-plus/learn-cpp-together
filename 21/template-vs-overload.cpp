/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 21.模板>> 配套例程
// template-vs-overload.cpp
// 模板与函数重载示例
//
/////////////////////////////////////////////////////////////////

#include <string>
#include <iostream>

template<class T1,class T2>
void f(T1 a, T2 b)
{
    std::cout<<"调用模板函数."<<std::endl;
}

void f(float a, float b)
{
    std::cout<<"调用重载函数."<<std::endl;
}

int main(void)
{
    float a = 10;
    double b= 13.1;
    f(a,b);
}

