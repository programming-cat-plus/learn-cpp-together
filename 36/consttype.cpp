#include <cmath>
#include <iostream>
class Complex{
public:
    constexpr Complex(double r=0,double i=0):_r(r),_i(i){}
    constexpr double getReal() const{return _r;}
    constexpr double getImaginary() const{return _i;}
    constexpr void setReal(double v) {_r=v;}
    constexpr void setImaginary(double v) {_i=v;}
private:
    double _r;
    double _i;
};

constexpr Complex multiply(const Complex& a,const Complex& b)
{   
    Complex res;

    res.setReal(a.getReal()*b.getReal()-a.getImaginary()*b.getImaginary());
    res.setImaginary(a.getReal()*b.getImaginary()+a.getImaginary()*b.getReal());

    return res;
}

int main(void)
{
    constexpr Complex a(1.7,3.8);
    constexpr Complex b(3.5,1.8);
    std::cout<<a.getReal()<<","<<a.getImaginary()<<std::endl;
    constexpr auto c = multiply(a, b);
    std::cout<<c.getReal()<<","<<c.getImaginary()<<std::endl;
}