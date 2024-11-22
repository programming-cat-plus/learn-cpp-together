/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 28.STL容器(2)>>视频配套例程
// del.cpp
// std::map erase函数示例
//
/////////////////////////////////////////////////////////////////
#include <iostream>
#include <map>

using namespace std;
int main(void){
    map<string, float> prices{{"01苹果",5.5},{"03香蕉",6.9,},{"02葡萄", 8.5}};
    
    int n = prices.erase("02苹果");
    for(const auto& p:prices)
        cout<<p.first<<":"<<p.second<<endl;
}