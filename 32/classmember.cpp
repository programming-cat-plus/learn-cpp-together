
/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 32.lambda表达式>> 配套例程
// classmember.cpp
// lambda捕获*this示例
//
/////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

class DemoClass{
private:
    int m_id;
public:
    DemoClass(int id):m_id(id){}
    void print(){
        [*this]() mutable {
            m_id++;//若去掉mutable，则这条语句错误
            cout<<"id = "<<m_id<<"\n";
        }();
    }

    void print1(){
        [=]() {
            m_id++;
            cout<<"id = "<<m_id<<"\n";
        }();
    }

    void print2(){
        [&]() {
            m_id++;
            cout<<"id = "<<m_id<<"\n";
        }();
    }

    auto getLambda(){
        return [*this] (){cout<<"id = "<<m_id<<"\n";};
    }
};

int main(void)
{
    DemoClass demo(-1);
    demo.print();
    auto f = demo.getLambda();
    f();
}