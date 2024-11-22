/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 21.函数模板>> 配套例程
// swap.cpp
// swap函数模板示例
//
/////////////////////////////////////////////////////////////////

#include <string>
#include <iostream>

//交换函数模板
template<class T>
void swap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

//一个swap函数模板的显示实例化
template void swap<int>(int& a,int& b);


//取最大值max函数模板：两个参数
template<typename T>
T max(T a, T b)
{
    std::cout<<"Template function call."<<std::endl;
    return a>b?a:b;
}

//取最大值max函数模板重载：三个参数
template<typename T>
T max(T a, T b, T c)
{
    std::cout<<"Template function call."<<std::endl;
    T temp =  a>b?a:b;
    return c>temp?c:temp;
}

//一个max函数模板的特化
template<>
double max<double>(double a, double b)
{
    std::cout<<"Specilized Template function call."<<std::endl;
    return a>b?a:b;
}

//有两个模板参数的函数模板
template<class T1,class T2>
T1 max(T1 a, T2 b)
{
    std::cout<<"Template function call."<<std::endl;
    return a>b?a:b;
}

//max函数模板的显示实例化
template float max<float>(float a, float b);

//max函数的重载,与上面的显示实例化有相同的函数签名
float max(float a, float b)
{
    std::cout<<"None template function call."<<std::endl;
    return a>b?a:b;
}

int main(void)
{
    //当函数模板与重载函数参数类型相同，实参完全匹配时，使用重载函数
    float a = 10;
    float b= 13.1;
    int c1 = max(a,b);
    
    //接上，这种情况使用模板函数需要显式调用
    max<float>(a,b);

    //当函数模板与重载函数都存在，实参不完全匹配，调用函数模板实例
    int c = 1.4;
    char aa = 14;
    float res = max(b,c);

    //调用特化版本
    float d= 2.3;
    double f=10.0,e=12.0;
    max(f,e);

    swap<float>((float&)c,d);

    std::string s1 = "Hello";
    std::string s2 = "World";
    swap(s1,s2);
}