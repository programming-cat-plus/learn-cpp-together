/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 15.类和对象（2）>> 配套例程
// inheritance.cpp
// 继承示例
//
/////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

class BaseClass{
public:
    BaseClass()
    {
        cout<<"基类构造函数被调用"<<endl;
    }

    ~BaseClass(){
        cout<<"基类析构函数被调用"<<endl;
    }
};

class SubClass: public BaseClass
{
private:
    string m_className;
public:
    SubClass():BaseClass(),m_className("SubClass")
    {
        cout<<"\t派生类构造函数被调用"<<endl;
    }

    ~SubClass(){
        cout<<"\t派生类析构函数被调用"<<endl;
    }
};

int main(void){
    BaseClass* pObj= new SubClass();
    delete pObj;
}
