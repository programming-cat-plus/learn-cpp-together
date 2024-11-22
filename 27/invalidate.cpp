/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 27.STL容器(1)>>视频配套例程
// invalidate.cpp
// std::vector iterator失效
//
/////////////////////////////////////////////////////////////////
#include <vector>
#include <iostream>
using namespace std;

int main(void){
    vector<int> numbers{1,2,3,4,5,6,7,8,9};
    auto it = numbers.begin();
    numbers.erase(numbers.end()-1);
    cout<<"插入之前*it="<<*it<<endl;
    auto it2 = numbers.insert(it,99);
    cout<<"插入之后*it="<<*it<<endl;
    cout<<"插入之后*it2="<<*it2;
    return 0;
}