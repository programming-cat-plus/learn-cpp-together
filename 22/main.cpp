/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 22.类模板>> 配套例程
// main.cpp
// 类模板应用示例
//
/////////////////////////////////////////////////////////////////

#include "vector3.h"
#include "nvector.h"
#include <iostream>
using namespace std;

int main(void)
{
    Vector3<int> vec1(1,2,3);
    Vector3<float> vec2(1.1,2.1,3.1);
    Vector3<char> vecchar('a','b','c');
    cout<<vecchar.asString()<<endl;

    // Vector<char>特化实例没有实现getMax()函数，所以下面这行会编译报错。
    vecchar.getMax();

    const int N = 5;
    float values[5] = {1.0f,-0.3f,0.7f,0.8f,1.2f};
    
    Vector<float,N> vec3(values);
    Vector<float,7> vec4{1.0f,-0.3f,0.7f,0.8f,5.2f,0.0f,0.3f};
    cout<<vec3.getMax()<<endl;
    Vector<float> defaultvector(values);
    cout<<defaultvector.getMax()<<endl;
}