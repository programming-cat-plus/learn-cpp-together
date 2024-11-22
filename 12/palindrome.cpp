/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 12.编程练习>> 配套例程
// palindrome.cpp
// 检查是否为回文
//
/////////////////////////////////////////////////////////////////
#include <iostream>
using namespace std;

bool panlindrome(int number)
{
    if(number<0)
        return false;

    int temp=0;
    int n = number;
    while(n)
    {
        temp*=10;
        temp+= n%10;
        n = n/10;
    }
    return number==temp;
}

int main(void)
{
    int a[]={121,133,123454321,110,001,010,-101,0,1};

    for(auto i:a)
    {
        if(panlindrome(i))
            cout<<i<<"是回文"<<endl;
        else
            cout<<i<<"不是回文"<<endl;
    }
        
}