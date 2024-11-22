/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 28.STL容器(2)>>视频配套例程
// lookup.cpp
// std::map lowerbound，upperbound函数示例
//
/////////////////////////////////////////////////////////////////

#include <iostream>
#include <map>

using namespace std;
int main(void){
    map<float,string> prices{{5.5f,"苹果"},{6.9f,"香蕉"},{8.5f,"葡萄"},{3.5f,"桔子"}};

    cout<<"Upper"<<endl;
    auto upper = prices.upper_bound(6.9f); 
    for(auto it=prices.begin();it!=upper;it++)
       cout<<it->first<<":"<<it->second<<endl;

    cout<<"Lower"<<endl;
    auto lower = prices.lower_bound(6.91f);
    for(auto it=lower;it!=prices.end();it++)
       cout<<it->first<<":"<<it->second<<endl;
}