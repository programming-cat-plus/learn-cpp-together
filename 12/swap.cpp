/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 12.编程练习>> 配套例程
// swap.cpp
// 交换两个变量的值
//
/////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

void swap(int& a, int& b)
{

    a = a^b;
    b = a^b;
    a = a^b;
}

void swap(float& a, float& b)
{
    float temp = a;

    a = b;
    b = temp;
}

int main(void)
{
    int a = 1, b= 2;
    float c = 3.1, d= 4.3;

    swap(a,b);
    swap(c,d);

    cout<<"a="<<a<<", ";
    cout<<"b="<<b<<", ";
    cout<<"c="<<c<<", ";
    cout<<"d="<<d<<", ";
    return 0;
}