/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 23.命名空间>> 配套例程
// foo.cpp
// 命名空间示例
//
/////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;
using std::cout;
namespace MyNamespace2{
    int foo(int a, int b);
}

int foo(int a, int b)
{
    cout<<"Global Foo"<<endl;
    return a*b;
}

namespace MyNamespace
{
    int foo(int a, int b)
    {
        cout<<"MyNamespace::Foo"<<endl;
        return a+b;
    }
}

namespace MyNamespace
{
    int mod(int a, int b)
    {
        return a%b;
    }
}

int a = 1;
namespace MyNamespace
{
    int a = 2;
    namespace A
    {
        int a =3;
    }
}

int main(void)
{
    foo(0,1);
    using MyNamespace::foo;
    MyNamespace::foo(0,1);
    foo(0,1);
    ::foo(0,1);
    MyNamespace2::foo(3,4);
    MyNamespace::mod(3,2);

    cout<<"::a="<<::a<<endl;
    cout<<"MyNamespace::a="<<MyNamespace::a<<endl;
    cout<<"MyNamespace::A::a="<<MyNamespace::A::a<<endl;
    using namespace MyNamespace::A;

    /* 命名空间不明确导致下面这行编译错误 */
    // cout<<"a="<<a<<endl; 
}