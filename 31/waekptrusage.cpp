/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 31.智能指针:shared_ptr和weak_ptr>> 配套例程
// waekptrusage.cpp
// weak_ptr示例
//
/////////////////////////////////////////////////////////////////

#include <memory>
#include <iostream>
using namespace std;

class A{};

int main(void)
{
    shared_ptr<A> sp1 = make_shared<A>();
    weak_ptr<A> wp1(sp1);
    weak_ptr<A> wp2;
    wp2 = sp1;

    cout<<"use count"<<wp2.use_count()<<endl;
}