/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 17.类域对象（3）>> 配套例程
// static.cpp
// 静态成员示例
//
/////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;
class Demo{
public:
    void cheer();
private:
    static unsigned int count;
    int a;
public:
    static void hello();
};

unsigned int Demo::count = 0;

void Demo::cheer(){
    count++;
    cout<<"Count="<<count;
}

void Demo::hello(){
    count++;
    Demo obj;
    obj.a = 2;
    cout<<"Hello, count="<<count;
}

int main(void)
{
    Demo demo;
    demo.hello();
    demo.cheer();
    Demo::hello();
}