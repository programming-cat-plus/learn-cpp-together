/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 28.STL容器(2)>>视频配套例程
// insert.cpp
// std::map insert函数示例
//
/////////////////////////////////////////////////////////////////

#include <iostream>
#include <map>

using namespace std;
int main(void){
    map<string, float> prices{{"01苹果",5.5},{"03香蕉",6.9,},{"02葡萄", 8.5}};
    
    prices["04火龙果"] = 9.5;
    prices.insert((std::make_pair("06桔子",3.0)));
    auto ret = prices.insert((std::make_pair("04火龙果",3.0)));

    for(const auto& p:prices)
        cout<<p.first<<":"<<p.second<<endl;
}