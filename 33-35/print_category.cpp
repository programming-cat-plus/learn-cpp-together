#include "value_cateory.h"
#include <iostream>
#include <string>
#define CAT(a) std::cout <<"Category of "<< #a << ":" <<VALUE_CATEGORY(a)<<std::endl
struct S{
    float m;
    S& operator+(int a){return *this;}
};
S func(int a){
    return S{};
}

struct B{
    float m;
};

int main(void){
    int i=1;
    int&& y = 4;
    S sa;
    S&& b = static_cast<S&&>(sa);
    CAT(i);
    CAT(6);
    CAT(S{});
    CAT(i++);
    CAT(i+1);
    CAT(i*4);
    S s;
    CAT(s);
    CAT(s+1);
    CAT(func);
    CAT(func(1));
    CAT(static_cast<S&&>(sa));
    CAT(S{});
    CAT(B{1.5}.m);
    float l = B{0.5}.m;

    CAT(y);
    b = S{};
    S (*f)(int) = &func; 
    std::string a;

}
