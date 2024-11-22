/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 24.异常>> 配套例程
// ex1.cpp
// 异常的抛出和捕捉示例
//
/////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

struct my_exception
{
    string mess;
    unsigned int errorno;
    const char* what(){return mess.c_str();}
};

class MyResource{
private:
    string m_name;
public:
    MyResource(const char* name):m_name(name){
        cout<<"MyResource Construct"<<m_name<<endl;
    }
    virtual ~MyResource(){
        cout<<"MyResource Destruct"<<m_name<<endl;
    }
};

void doSomething()
{
    //自动对象在抛出异常时会自动释放
    MyResource res("[doSomething]");
    cout<<"doSomething()"<<endl;
    throw runtime_error("do something error");
}

int main()
{
    try{
        //动态分配的对象在抛出以后无法释放，造成内存泄漏。
        MyResource* pRes = new MyResource("[main]");
        doSomething();
        delete pRes;
    }
    catch(runtime_error& e)
    {
        cout<<e.what()<<endl;
    }
}