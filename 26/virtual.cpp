/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 26.函数指针>>视频配套例程
// virtual.cpp
// 成员函数指针的多态示例
//
/////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

class BaseClass{
public:
    virtual void print(){cout<<"Base Class"<<endl;}
};

class SubClass:public BaseClass{
public:
    void print() override {cout<<"Sub Class"<<endl;}
};

void BasePrint(){
    void (BaseClass::*pMemFunc)() = BaseClass::print;

    BaseClass *pObj = new SubClass();
    SubClass obj2;
    (pObj->*pMemFunc)();
}

int main(void){
    BasePrint();
}