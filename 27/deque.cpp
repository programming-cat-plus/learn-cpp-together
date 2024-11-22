/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 27.STL容器(1)>>视频配套例程
// deque.cpp
// std::deque示例
//
/////////////////////////////////////////////////////////////////
#include <deque>
#include <iostream>
using namespace std;

int main(void)
{
    deque<float> dq{1,2,3,4,5};
    dq.push_front(0.2);
    dq.push_back(0.3);
    
}