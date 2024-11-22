/////////////////////////////////////////////////////////////////
//
// <<一起来学C++ 29.函数封装与绑定>>视频配套例程
// memfn.cpp
// mem_fn示例
//
/////////////////////////////////////////////////////////////////

#include <functional>
#include <iostream>

struct Foo{
    float w;
    float calculate(float a,float b){return w*a+w*b;}
    Foo& operator+=(float a){w+=a;return *this;}
    void print(){std::cout<<"w="<<w<<std::endl;}
};

int main(){
    Foo f{1.0};

    auto memfn = std::mem_fn(&Foo::calculate);
    float res = memfn(f,2.0,3.0);
    std::cout<<"res="<<res<<std::endl;
    
    auto op_add_assign = std::mem_fn(&Foo::operator+=);
    auto f2 = op_add_assign(f,2.0);
    f2.print();
}
