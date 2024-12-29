#include <cmath>
#include <type_traits>
#include <iostream>
#include <vector>

class IMeasurable{
public:
    virtual double length()=0;
};

class Complex:public IMeasurable{
public:
    Complex(double r,double i):imaginary(i),real(r){};
    double length() override{return std::sqrt(imaginary*imaginary+real*real);}
private:
    double imaginary=0;
    double real=0;
};

template<typename T>
double length(T& t){
    if(std::is_arithmetic_v<T>)
    {
        if(t<0)
            return -t;
        return t;   
    }
    else if(std::is_base_of_v<IMeasurable,T>)
        return t.length();
    return 0;

}

int main(){
    double l = -13.5;
    std::cout<<length(l)<<"\n";
}