/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 26.函数指针>>视频配套例程
// memberfunctionp.cpp
// 成员函数指针
//
/////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

class DemoClass{
public:
    double add(double a,double b){
        return a+b;
    }

    double multiply(double a,double b){
        return a*b;
    }
};

int main(void)
{
    double (DemoClass::*ptrMemberFunc)(double,double);
    ptrMemberFunc = DemoClass::add;

    DemoClass obj;
    double result = (obj.*ptrMemberFunc)(0.5,2.1);
    cout<<result<<endl;

    DemoClass* pObj;
    ptrMemberFunc = &DemoClass::multiply;
    result = (pObj->*ptrMemberFunc)(0.5,2.1);
    cout<<result<<endl;
}