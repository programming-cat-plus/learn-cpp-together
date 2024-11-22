/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 25.类型转换>>视频 配套例程
// explicit.cpp
// 显式转换示例
//
/////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;
void basetype();

int main(void){
    basetype();
    return 0;
}

void basetype(){
    int a = 2;
    float b = float(a);
    b = 3.5f;
    double c = 3.5e39;
    b = c;
    cout<<b<<endl;
}

class BaseClass{
protected: 
    int m_a;
public:
    BaseClass():m_a(0){};
};

class SubClass:public BaseClass{
public:
    SubClass(){};
};

class ClassA {};
class ClassB { 
public: 
    ClassB (const ClassA& a) {} 
};

void classType(){
    SubClass obj;
    BaseClass* pBase = (BaseClass*)&obj;
    ClassB* pB;
    //pB = (BaseClass*)&obj; /*错误，不兼容的类型转换*/
}

void convertConstructor(){
    ClassA a;
    ClassB b=a;
}

