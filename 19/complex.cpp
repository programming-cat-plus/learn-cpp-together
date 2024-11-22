/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 19.运算符重载>> 配套例程
// operator.cpp
// 类内外运算符重载示例
//
/////////////////////////////////////////////////////////////////

#include <iostream>
#include <format>
#include <string>
using namespace std;
class Complex
{
    public:
        float r;
        float i;
    public:
        Complex(float real,float imaginary):r(real),i(imaginary){};

        Complex operator+(const Complex& other) const{
            return Complex(this->r+other.r,this->i+other.i);
        }
        operator float(){
            return i;          
        }

        Complex operator+(float r) const{
            return Complex(this->r+r,this->i);
        }
    friend Complex operator+(float a, const Complex& b)
    {
        return b+a;
    }
};

int main(void)
{
    Complex a(0.1,2);
    Complex b(0.4,-2.1);
    Complex c = a + b;
    c = a.operator+(b);
    cout<<"("<<c.r<<","<<c.i<<")"<<endl;


    c= c + 1.1f;
    c= 1.0f + c;
    c = operator+(1.5,c);
    cout<<float(c)<<endl;
};

