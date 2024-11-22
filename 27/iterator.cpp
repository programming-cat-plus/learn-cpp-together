/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 27.STL容器(1)>>视频配套例程
// iterator.cpp
// std::vector::iterator示例
//
/////////////////////////////////////////////////////////////////
#include <vector>
#include <iostream>
using namespace std;

int main(void){
    vector<int> numbers{1,2,3,4,5};
    vector<int>::iterator it;
    for(it = numbers.end()-1;it>=numbers.begin();--it)
    {
        cout<<*it<<" ";
    }
}

