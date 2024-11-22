/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 17.类域对象（3）>> 配套例程
// parent.cpp
// 类的继承示例
//
/////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

class BaseClass{
private:
    int m_a;
public:
    BaseClass():m_a(0){};
    virtual void hello(){
        cout<<"Hello from Base"<<endl;
    };
};

class SubClass:public BaseClass{
public:
    void hello(){
        cout<<"Hello from Subclass"<<endl;
        BaseClass::hello();
    };
};

int main(void){
    SubClass obj;
    BaseClass *p = &obj;
    p->hello();
}