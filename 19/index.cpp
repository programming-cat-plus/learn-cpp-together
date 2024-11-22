/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 19.运算符重载>> 配套例程
// index.cpp
// 下标运算符重载示例
//
/////////////////////////////////////////////////////////////////

#include <cassert>
#include <vector>
#include <iostream>
using namespace std;

class Array{
private:
    vector<float> numbers;
public:
    Array(vector<float> n):numbers(n){};
    float operator[](int i)
    {
        int size =  numbers.size();
        assert(i<size&&i>-size);

        if(i<0)
            return numbers[size+i];

        return numbers[i];
    }
};

int main(void)
{
    Array arr(vector<float>{1,2,3,4,5,6,7,8,9,10});

    cout<<arr[1]<<endl;
    cout<<arr[-1]<<endl;
     cout<<arr[10]<<endl;
}

