/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 28.STL容器(2)>>视频配套例程
// multimap.cpp
// std::multimap示例
//
/////////////////////////////////////////////////////////////////


#include <iostream>
#include <map>
using namespace std;

int main(void){
    multimap<float,string> prices{{5.5f,"苹果"},{6.9f,"香蕉"},{8.5f,"葡萄"},{3.5f,"桔子"}};

    prices.insert(pair(3.5f,"橙子"));
    auto r = prices.equal_range(3.5f);
    for(auto it = r.first;it!=r.second;it++)
    {
        cout<<it->second<<"; ";
    }
}