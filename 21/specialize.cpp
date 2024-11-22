/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 21.模板>> 配套例程
// specialize.cpp
// 模板特化示例
//
/////////////////////////////////////////////////////////////////
#include <string>
#include <iostream>

template<class T1,class T2>
void f(T1 a, T2 b)
{
    std::cout<<"调用模板函数."<<std::endl;
}

template<>
void f<int,float>(int a, float b)
{
    std::cout<<"调用特化函数f(int,float)."<<std::endl;
}

int main(void)
{
    int a = 10;
    float b= 13.1;
    f(a,b);
    f(b,a);
}

