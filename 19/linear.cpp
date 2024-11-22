/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 19.运算符重载>> 配套例程
// linear.cpp
// 函数调用外运算符重载示例
//
/////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

struct LinearFunction{
    double k;
    double b;
    double operator()(double x) const{
        return k*x+b;
    }
};


int main(void)
{
    LinearFunction f{1.5,3};
    cout<<"f(0)="<<f(0)<<endl;
    cout<<"f(3)="<<f(3)<<endl;
}