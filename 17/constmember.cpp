/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 17.类域对象（3）>> 配套例程
// constmember.cpp
// const对象示例
//
/////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

class Complex{
private:
    float r;
    float i;
    const int a=10;
public:
    Complex(float r,float i){
        this->r= r;
        (*this).i= i;
    };
    Complex& add(const Complex& other){

        i+=other.i;
        r+=other.r;
        return *this;
    }
    void print() 
    {   
        Complex b(1,2);
        cout<<r<<"+"<<i<<"i"<<endl;
    }
};

int main(void)
{
    Complex a(1.0,2), b(2.3,-2),c(1.1,1.3);
    const Complex d(9.0,9.0);
    a.add(b).add(c);
    a.print();
    //以下两行错误
    //d.print();
    //d.add(b);
    Complex& temp = a.add(b);
    temp.add(c);
}