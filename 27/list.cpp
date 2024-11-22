/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 27.STL容器(1)>>视频配套例程
// list.cpp
// std::list示例
//
/////////////////////////////////////////////////////////////////
#include <list>
#include <iostream>
using namespace std;

int main(void){
    list<int> ls{1,2,3,4,5};
    auto it = ls.begin();
    it++;
    cout<<*it<<endl;
    ls.insert(it,-1);
    cout<<*it<<endl;
    ls.erase(ls.begin());
    cout<<*it<<endl;
}