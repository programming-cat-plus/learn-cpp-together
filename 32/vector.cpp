/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 32.lambda表达式>> 配套例程
// vector.cpp
// 将lamda作为函数参数使用示例
//
/////////////////////////////////////////////////////////////////

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main(void)
{
    vector<float> numbers{1.1,2.0,3.5,-1.4,29.2,12.1,33,6,0};
    sort(numbers.begin(),numbers.end(),[](float a,float b){return a<b;});
    for(auto v:numbers)
        cout<<v<<" ";
}