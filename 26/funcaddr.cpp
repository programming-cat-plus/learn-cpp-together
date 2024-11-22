/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 26.函数指针>> 配套例程
// functaddr.cpp
// 打印函数地址示例
//
/////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

double multiply(double a,double b)
{
    return a*b;
}

//打印数组的地址和函数的地址
int main(void)
{
    int numbers[]={1,2,3,4,5};
    cout<<hex<<(unsigned long long)numbers<<endl;

    cout<<hex<<(unsigned long long)multiply<<endl;
}