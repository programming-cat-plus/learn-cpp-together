/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 23.命名空间>> 配套例程
// throw.cpp
// 抛出各类异常示例
//
/////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;
struct my_exception
{
    string mess;
    unsigned int errorno;
};

string exception_func()
{
    return "这是一个函数异常";
}

int main(void){

    try{
        throw "这是一个字符串异常";
    }
    catch(const char* e)
    {
        cout<<e<<endl;
    }

    try{
        throw 42;
    }
    catch(int e)
    {
        cout<<e<<endl;
    }

    try{
        throw exception_func;
    }
    catch(string (*e)())
    {
        cout<<e()<<endl;
    }

    try{
        throw my_exception{"My exception",1000};
    }
    catch(my_exception& e)
    {
        cout<<e.mess<<":"<<e.errorno<<endl;
    }

}