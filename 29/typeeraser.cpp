/////////////////////////////////////////////////////////////////
//
// <<一起来学C++ 29.函数封装与绑定>>视频配套例程
// typeeraser.cpp
// 类型擦除示例
//
/////////////////////////////////////////////////////////////////

#include <map>
#include <functional>
#include <iostream>

float add(float a, float b)
{
    return a+b;
}

struct Substract{
    float operator()(float a, float b){return a-b;}
};

int main(void)
{
    std::map<char, std::function<double(double,double)>> calculator{
        {'+',add},
        {'-',Substract()},
        {'*',[](double a,double b)->double {return a*b;}}
    };

    std::cout<<calculator['+'](12.0,13)<<std::endl;
    std::cout<<calculator['-'](13.0,6.2)<<std::endl;
    std::cout<<calculator['*'](2.3,3.2)<<std::endl;
}












