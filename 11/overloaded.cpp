/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 11.函数（下）>> 配套例程
// overloaded.cpp
// 函数重载示例
//
/////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
using namespace std;

inline float multiply(float a,float b){
    return a*b;
};

float multiply(float a,float b, float c){
    return a*b*c;
};

int multiply(int a,int b){
    return a*b;
};


int main(void){
    int a=2,b=5,c=9;
    float x=3.5,y=-5.7;

    cout<<multiply(a,b)<<endl;
    cout<<multiply(a,b,c)<<endl;
    cout<<multiply(x,y)<<endl;
    cout<<multiply(3,4);

    string s1="Hello";
    string s2 ="World";
    string s3 = s1+s2;
    
}