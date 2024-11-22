/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 32.lambda表达式>> 配套例程
// lambdastruct.cpp
// lambda结构示例
//
/////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

struct ClosureType{
    int _x;
    float _y;
    float operator()(int a,int b)
    {
        return _x*_y+a*b;
    }
};


int main(void)
{
    int x = 7;
    float y = 3.0;
    auto p = ClosureType{x,y};

    struct {
        int& _x;
        float _y;
        float operator()(int a,int b) const
        {
            _x++;
            return _x*_y+a*b;
        }
    }p1{x,y};

    cout<<p(10,20)<<endl;
    cout<<p1(10,20)<<endl;
}