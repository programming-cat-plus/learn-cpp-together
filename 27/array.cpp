/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 27.STL容器(1)>>视频配套例程
// array.cpp
// std::array示例
//
/////////////////////////////////////////////////////////////////

#include <array>
#include <iostream>
using namespace std;

int main(void)
{
    array<float,5> numbers{1,2,3,4,5};
    for(auto v:numbers)
        cout<<v<<" ";
}