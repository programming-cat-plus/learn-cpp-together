/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 19.运算符重载>> 配套例程
// insertion.cpp
// 插入运算符<<重载示例
//
/////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
using namespace std;

ostream& operator<<(ostream& o,const vector<int>& numbers){
    o<<"[";

    unsigned int last = numbers.size()-1;
    for(int i=0;i<last;i++)
        o<<numbers[i]<<",";
    o<<numbers[last]<<"]";
    return o;
}

int main(void){
    
    vector<int> numbers{1,3,5,7,9};
    cout<<numbers<<endl;
    operator<<(cout,numbers);
    
    cout<<"Hellp, World";
    
    int a = 3;
    a = a<<3;
}