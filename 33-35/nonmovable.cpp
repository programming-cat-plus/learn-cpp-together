#include <iostream>
using namespace std;

class MyClass{
public:
    MyClass(int a,int b):m_a(a),m_b(b){}
    MyClass(const MyClass& other):m_a(other.m_a),m_b(other.m_b)
    {
        cout<<"Copy Constructor Called"<<endl;
    }
private:
    int m_a;
    int m_b;
};

int main(void)
{
    MyClass a(1,2);
    MyClass b(std::move(a));
    MyClass c(MyClass(3,4));
}