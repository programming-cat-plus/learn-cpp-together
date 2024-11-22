/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 11.函数（下）>> 配套例程
// fib.cpp
// 函数的递归调用 - 斐波那契数列
//
/////////////////////////////////////////////////////////////////

#include <iostream>

using namespace std;

unsigned int fib(unsigned int n);
unsigned int fib2(unsigned int n);

int main(void)
{
    for(int i=0;i<50;i++)
        cout<<"fib("<<i<<") = "<< fib(i) << endl;
   
    return 0;
}

unsigned int fib(unsigned int n)
{  
    if(n<=1)
        return 1; 
    return fib(n-1)+fib(n-2);
}



unsigned int fibonacci[50]={0};

unsigned int fib2(unsigned int n)
{  
    if(n<=1)
        return 1;
    
    if(n>=50) //太大了，b
        return -1;

    if(fibonacci[n])
        return fibonacci[n];

    fibonacci[n] = fib(n-1)+fib(n-2);
    if(n==90)
        cout<<";";
    return fibonacci[n];
}


unsigned int fib3(unsigned int n)
{ 
    if(n<=1)
	    return 1;
    int fn_2 = 1;
    int fn_1 = 1;
    int fn = 0;
	for(int i=2;i<n;i++)
    {
        fn = fn_2 + fn_1;
        fn_1 = fn_2;
        fn_2 = fn;
    }
    return fn;
}
