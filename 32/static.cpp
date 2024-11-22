/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 32.lambda表达式>> 配套例程
// static.cpp
// lamda直接使用静态变量示例
//
/////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;
int main(void)
{
    float k=1.0;
    float b=2.0;
    const int N = 10;
    static float m = 2.5;
    auto f = [k,b](float x){return k*x+b+N+m;};

    cout<<f(3)<<endl;
}