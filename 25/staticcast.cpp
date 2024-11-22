/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 25.类型转换>>视频 配套例程
// staticcast.cpp
// static_cast示例
//
/////////////////////////////////////////////////////////////////
#include <iostream>
using namespace std;

class CBase{
public:
    virtual void print(){
        cout<<"CBase"<<endl;
    }
};

class CDerive:public CBase{
public:
    void print() override{
        cout<<"CDerive"<<endl;
    }
};

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
    CBase& f = obj;
    f.print();
    p = static_cast<CBase*>(&obj);
    p1 = static_cast<CDerive*>(&obj);

    //p = static_cast<CBase*>(&other);
    //p1 = static_cast<CDerive*>(&other);
    
    float b =3.6;
    double c = 3.5e39;
    b = c;
    //c = {b};
    convert();
}