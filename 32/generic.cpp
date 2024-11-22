/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 32.lambda表达式>> 配套例程
// generic.cpp
// lambda泛型示例
//
/////////////////////////////////////////////////////////////////
#include <iostream>
using namespace std;

template<class T1,class T2>
struct ClosureType{
    auto operator()(T1 x, T2 y){return x+y;};
};

int main(void)
{
    auto f= [](auto x,auto y){return x+y;};
    cout<<f(string("abc"),string("def"))<<endl;
    cout<<f(1.2,3.4)<<endl;
}