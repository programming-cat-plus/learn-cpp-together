/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 23.命名空间>> 配套例程
// globalvslocal.cpp
// 命名空间示例
//
/////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

int a = 1;
namespace MyNamespace
{
    int a = 2;
    namespace A
    {
        int a = 3;
    }
}


int main(void)
{
    using MyNamespace::A::a;
    cout<<a<<endl;
}
