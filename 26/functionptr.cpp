/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 26.函数指针>> 配套例程
// functionptr.cpp
// 函数指针调用示例
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

#define MyFuncPtr(ptr) double (*ptr)(double a,double b)
int main(void){
    double (*ptr)(double a,double b) = multiply;
    double res = ptr(4.2,1.5);

    cout<<res<<endl; 
    ptr = &add;
    res = ptr(4.2,1.5);
    cout<<res<<endl; 
    return 0;
    
    MyFuncPtr(ptr1) = multiply;
    int (*ptr2)(int,int);
    res = ptr1(0.4,1.5);
    cout<<res<<endl;

    ptr1 = add;
    res = (*ptr1)(4,1);
    cout<<res<<endl;
}