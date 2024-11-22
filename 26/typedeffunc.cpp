/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 26.函数指针>>视频配套例程
// typedeffunc.cpp
// 使用typedef定义函数指针
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

int add(int a, int b)
{
    return a+b+1;
}

typedef double (*MyFuncTypePtr)(double,double);
typedef double (MyFuncType)(double,double);

int main(void){
    MyFuncTypePtr ptr1 = multiply;

    double res = ptr1(0.4,1.5);
    cout<<res<<endl;

    MyFuncType* ptr2 = add;
    res = ptr2(4,1);
    cout<<res<<endl;
}