/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 27.STL容器(1)>>视频配套例程
// itadd.cpp
// std::vector 循环中添加元素示例
//
/////////////////////////////////////////////////////////////////

#include <vector>
#include <iostream>
using namespace std;

int main(void){
    vector<int> numbers{1,2,3,4,5,6,7,8,9};
    for(auto it = numbers.begin();it!=numbers.end();++it){
        if(*it%2){   
            ++it;
            it = numbers.insert(it,0);
        }
    }
    for(auto n:numbers)
        cout<<n<<" ";
}