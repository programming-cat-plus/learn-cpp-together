/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 17.类域对象（3）>> 配套例程
// override.cpp
// 类的重写示例
//
/////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

class BaseClass {
public:
     virtual int  DoSomething(int val)
    {
        cout<<"BaseClass:DoSomething("<<val<<")"<<endl;
        return val;
    }
    int final(){

    }
    void override();
};

class SubClassA final:public BaseClass{
public:
    virtual int DoSomething(int val) override
    {
        cout<<"SubClass:DoSomething("<<val<<")"<<endl;
        return val;
    }
};

//错误：无法继承final类
class SubClassB :public SubClassA{
public:
    virtual int DoSomething(int val) 
    {
        cout<<"SubClass:DoSomething("<<val<<")"<<endl;
        return val;
    }
};

int main(void)
{
    BaseClass* pObj = new SubClassA();
    int a = 10;
    pObj->DoSomething(a);

    delete pObj;
}