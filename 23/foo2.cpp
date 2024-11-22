/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 23.命名空间>> 配套例程
// foo2.cpp
// 命名空间示例
//
/////////////////////////////////////////////////////////////////
#include <iostream>

using namespace std;

namespace MyNamespace2{
    int foo(int a, int b)
    {
        cout<<"MyNamespace2:foo"<<endl;
        return a+b;
    }
}