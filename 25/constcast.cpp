/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 25.类型转换>> 配套例程
// constcast.cpp
// const_cast示例
//
/////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

void func(int& a)
{
    a++;
};

void hello(char* str)
{
    str[0] = 'A';
    cout<<"hello, "<<str<<endl;
};

int main(void)
{
    const int b = 14;
    const char* str = "world!";
    
    //下面这行是常量转换为非常量后，修改内存导致的Segment Fault示例
    hello(const_cast<char*>(str));
    
    func(const_cast<int&>(b));
    cout<<b<<endl;
}