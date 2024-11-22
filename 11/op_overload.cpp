/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 11.函数（下）>> 配套例程
// op_overload.cpp
// 运算符函数重载示例
//
/////////////////////////////////////////////////////////////////


#include <iostream>
#include <ostream>
#include <vector>

using namespace std;
float multiply(float a, float b);

template<typename T>
ostream& operator<<(ostream& out,vector<T> vec)
{
    for(auto i:vec)
        out<<i<<",";
    return out;
}

int main(void){
    float res=0;
    float m = 3.5;
    float n = 2.72;
    res = multiply(m, n);
    std::cout<<res<<std::endl;

    vector<float> vec = {3.1,4,1,2,3,5.2,7,4};
    cout<<vec<<endl;
}

float multiply(float a, float b)
{
    float result=0;
    result = a*b;
    return result;
};