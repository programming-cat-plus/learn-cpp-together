/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 31.智能指针:shared_ptr和weak_ptr>> 配套例程
// cast.cpp
// xxx_pointer_cast示例
//
/////////////////////////////////////////////////////////////////

#include <memory>
#include <iostream>
using namespace std;

class Base{
public:
    virtual ~Base(){}
};

class Derive:public Base{
};

int main(){
    shared_ptr<Base> sp1(new Derive());
    shared_ptr<Derive> sp2 = dynamic_pointer_cast<Derive>(sp1);
    shared_ptr<Base> sp3 = static_pointer_cast<Base>(sp2);
    cout<<"use count="<<sp1.use_count()<<endl;
}