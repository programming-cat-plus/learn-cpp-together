/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 22.类模板>> 配套例程
// ttp.cpp
// 模板参数模板(Template template paramter)示例
//
/////////////////////////////////////////////////////////////////

#include <iostream>
#include <set>
#include <vector>

using namespace std;

template<template <typename> typename Container,typename T>
class Wrapper
{
private:
    Container<T> m_values;
public:
    Wrapper(const Container<T>& o):m_values(o){}
    void print(){
        for(auto v:m_values)cout<<v<<" ";
    }
};

int main(){
    vector<int> ls = {1,5,3,2,4,3,4,5};
    Wrapper<vector,int> example(ls);
    example.print();
}