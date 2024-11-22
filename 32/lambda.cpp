/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 32.lambda表达式>> 配套例程
// lambda.cpp
// lambda示例
//
/////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

int main(void)
{
    int x=7;
    float y=3.0;
    auto p = [x,y](int a, int b)-> float{
        //x++; 
        return x*y+a*b;
    };
    
    cout<<p.__x<<", "<<p.operator()(10,20);
}

