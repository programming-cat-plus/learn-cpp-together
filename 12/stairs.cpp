/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 12.编程练习>> 配套例程
// stairs.cpp
// 爬楼梯问题
//
/////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;


int calc(int n)
{
    if(n<0)
        return 0;
    
    int dp[n+1] = {0,1,2};

    for(int i=3;i<=n;i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

int main(void)
{
    for(int i=1;i<40;i++)
    {
        cout<<"("<<i<<") "<<calc(i)<<endl;
    }
    return 0;
}