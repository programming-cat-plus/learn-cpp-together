/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 9.编程练习>> 配套例程
// bubble.cpp
// 冒泡排序法
//
/////////////////////////////////////////////////////////////////

#include <vector>
#include <iostream>

using namespace std;

void test(int a,int b,...)
{

}

float multiply(float a,float b=10)
{
   int result;
   result = a*b; 
   return result; 
}
    
int main(void)
{

    float m = 3.1, n = 4.5;
    float l;
    l = multiply(m,n);

    l = multiply(m);
    cout<<"l="<<l<<endl;

    vector<int> numbers;
    int num;
    cout<<"请输入要排序的整数，以空格隔开，以分号结束:"<<endl;

    while(cin>>num)
    {
        numbers.push_back(num);
    }

    for(int k=numbers.size();k>1;)
    {
        int m=0;

        for(int i=0;i<k-1;i++)
        {
           if( numbers[i]>numbers[i+1])
           {
                int temp =  numbers[i];
                numbers[i] = numbers[i+1];
                numbers[i+1] = temp;
                m = i+1;
           }
        }

        k=m;
    }

    for(int num:numbers)
        cout<<num<<" ";
    return 0;
}