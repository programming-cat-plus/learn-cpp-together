/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 15.类和对象（2）>> 配套例程
// inheritance3.cpp
// 继承示例
//
/////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

class BaseClass{
public:
    void greet(){
        cout<<"这是基类"<<endl;
    }
};

class SubClass:public BaseClass
{
public:
    void greet()
    {
        cout<<"这是子类"<<endl;
    }
};

int main(void){
    SubClass obj;
    BaseClass* pBase = &obj;
    obj.greet();
    pBase->greet();
}
