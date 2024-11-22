/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 22.类模板>> 配套例程
// main.cpp
// 类模板部分特化应用示例
//
/////////////////////////////////////////////////////////////////

#include "mypair.h"

int main(void)
{
    MyPair<double,double> generic(0.1,1.2);
    generic.print();


    MyPair<int,double> partial1(3,1.2);
    partial1.print();

    MyPair<double,float> partial2(1.2,1);
    partial2.print();
    

    float *pA = new float(3);
    float *pB = new float(4.5);

    MyPair<float*,float*> partial3(pA,pB);
    partial3.print();

    MyPair<int,float> partial4(1.2,1);
    partial4.print();

    return 0;
}