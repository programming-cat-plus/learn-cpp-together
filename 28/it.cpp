/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 28.STL容器(2)>>视频配套例程
// insert.cpp
// std::map iterator示例
//
/////////////////////////////////////////////////////////////////

#include <iostream>
#include <map>

using namespace std;
int main(void){
    map<string, float> prices{{"01苹果",5.5},{"03香蕉",6.9,},{"02葡萄", 8.5}};
    
    //使用for range遍历
    for(const auto& p:prices)
        cout<<p.first<<":"<<p.second<<endl;
    
    //使用iterator遍历
    for(auto it=prices.cbegin();it!=prices.cend();it++)
        cout<<it->first<<":"<<it->second<<endl;
}