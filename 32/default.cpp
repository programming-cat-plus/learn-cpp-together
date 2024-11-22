/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 32.lambda表达式>> 配套例程
// default.cpp
// lambda默认捕获示例
//
/////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

int main(void)
{
    int x=7;
    float y=3.0;
    float z = -1;

    auto p = [=,&y](int a, int b)->float{
        return x*y+a*b;
    };
    cout<<p(10,20);
}