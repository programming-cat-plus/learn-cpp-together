/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 32.lambda表达式>> 配套例程
// outofscope.cpp
// lamda捕获引用离开作用域错误示例
//
/////////////////////////////////////////////////////////////////

#include <functional>
#include <iostream>
using namespace std;

auto createLambda()
{
    float x = 1.0;
    float y = 2.0;
    return [&](float a){return a*x+y;};
}

int main(void)
{
    auto f = createLambda();
    cout<<f(2.0)<<endl;
}