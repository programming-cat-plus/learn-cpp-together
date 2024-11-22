/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 28.STL容器(2)>>视频配套例程
// unordered.cpp
// std::map unordered_set函数示例
//
/////////////////////////////////////////////////////////////////

#include <unordered_set>
#include <iostream>
using namespace std;

int main(void)
{
    unordered_set<string> fruits{"苹果","香蕉","桔子","梨","葡萄"};
   
    fruits.insert("梨");
    fruits.erase("香蕉");

    for(auto f:fruits)
        cout<<f<<" ";
}