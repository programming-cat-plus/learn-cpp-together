/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 28.STL容器(2)>>视频配套例程
// set.cpp
// std::set示例
//
/////////////////////////////////////////////////////////////////

#include <iostream>
#include <set>

using namespace std;
int main(void){
    set<string> prices{"01苹果","03香蕉","04葡萄","02桔子"};

    for(auto p:prices)
        cout<<p<<" ";
}

template<
    class Key,
    class T,
    class Compare = std::less<Key>,
    class Allocator = std::allocator<std::pair<const Key, T>>

> class multimap;