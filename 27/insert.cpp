/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 27.STL容器(1)>>视频配套例程
// insert.cpp
// std::vector insert函数示例
//
/////////////////////////////////////////////////////////////////

#include <vector>
#include <iostream>
using namespace std;

int main(void){
    vector<int> numbers{1,2,3,4,5};
    auto it = numbers.begin();
    it = numbers.insert(it,-1);
    cout<<*it<<endl;

    for(it = numbers.begin();it!=numbers.end();++it)
    {
        cout<<*it<<" ";
    }
}