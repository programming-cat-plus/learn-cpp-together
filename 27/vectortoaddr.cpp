/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 27.STL容器(1)>>视频配套例程
// vectortoaddr.cpp
// std::vector vector与指针的转换
//
/////////////////////////////////////////////////////////////////

#include <vector>
#include <iostream>
using namespace std;

int main(void){
    vector<int> numbers{1,2,3,4,5};
    auto it = numbers.begin();
    int *ptr = &(*it);

    for(int i=0;i<5;i++){
        *ptr*=2;
        ptr++;
    }

    for(auto n:numbers)
        cout<<n<<" ";
}