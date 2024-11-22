/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 10.函数>> 配套例程
// ex1.cpp
// 函数示例
//
/////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

#if 1
int inc(int v)
{
    v++;
    return v;
}
#else
int inc(int& v)
{
    v++;
    return v;
}
#endif
float power (float base, float exponent);
float multiply(float,float);

//错误的默认值
int demoFunc(int a, int b,int c=0, int b=0)
{
    return 0;
}

int main(void)
{
    int a = 1;
    int res = 0;

    res = inc(a);
    cout<<"a="<<a<<endl;
    cout<<"res="<<res<<endl;

    return 0;
}