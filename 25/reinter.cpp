/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 25.类型转换>>视频 配套例程
// reinter.cpp
// 示例
//
/////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

class CBase{};
class CDerive:public CBase{};

class ClassA {};
class ClassB { 
    public: ClassB (const ClassA& a) {} 
};

class COther{};
void convert(){
    float m = 1.2;
    double n = static_cast<double>(m);
    m = n;
    ClassA a;
    ClassB B = static_cast<ClassB>(a);
    ClassB c = a;
}

int main(void){
    CBase *p;
    CDerive *p1;
    COther other;
    CDerive obj;

    p = reinterpret_cast<CBase*>(&other);
    p1 = reinterpret_cast<CDerive*>(&other);
    p1 = reinterpret_cast<CDerive*>(0xEFL);
    //long address= reinterpret_cast<long>(&other);
    long long address= reinterpret_cast<long long>(&other);
    CDerive& obj1 = reinterpret_cast<CDerive&>(obj);
    convert();
}