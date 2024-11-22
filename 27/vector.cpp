/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 27.STL容器(1)>>视频配套例程
// vector.cpp
// std::vector 下标越界、size、capacity示例
//
/////////////////////////////////////////////////////////////////

#include <vector>
#include <iostream>
using namespace std;

int main(void)
{
    vector<int> numbers = {1,2,3,4,5};
    vector<int> numbers1{1,2,3,4,5};
    
    //下标越界不做检查导致未知错误
    numbers[10] = 30;
    cout<<numbers[20]<<endl;

    numbers[10]++;
    cout<<numbers[1]<<endl;

    //size和capacity的区别
    float value = 3.0;
    vector<float> values{1.0};
    values.push_back(6.6);
    values.pop_back();
    cout<<values[0]<<endl;
    cout<<"Capacity="<<values.capacity()<<endl;
    cout<<"Size="<<values.size()<<endl;
}