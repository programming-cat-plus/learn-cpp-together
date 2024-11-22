/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 26.函数指针>> 配套例程
// auto.cpp
// 获得函数指针示例
//
/////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

double multiply(double a,double b)
{
    return a*b;
}

double add(double a,double b)
{
    return a+b;
}


typedef double (*MyFuncPtr)(double a, double b);

int main(void){
    auto funcPtr = multiply;
    double res = funcPtr(4.2,1.5);
    
    MyFuncPtr ptrs[2]={add,multiply};
    ptrs[0](4.2,1.5);
}