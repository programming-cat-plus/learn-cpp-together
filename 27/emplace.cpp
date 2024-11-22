/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 27.STL容器(1)>>视频配套例程
// emplace.cpp
// std::vector emplace函数示例
//
/////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
using namespace std;

class  Complex{
protected:
    double m_i;
    double m_r;
public:
    Complex(double i,double r):m_i(i),m_r(r){
        cout<<"构造函数"<<endl;
    }
    Complex(const Complex& other):m_r(other.m_r),m_i(other.m_i){
        cout<<"拷贝构造函数"<<endl;
    }
};

int main(){
    cout<<"\n----------Push Back-----------"<<endl;
    vector<Complex> values;   
    Complex value(0.1,-2);
    values.push_back(value);

    cout<<"\n---------Emplace back----------"<<endl;
    vector<Complex> values2;
    values2.emplace_back(0.1,0.2);
}
