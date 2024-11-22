/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 18.结构与联合>> 配套例程
// structbit.cpp
// struct位定义示例
//
/////////////////////////////////////////////////////////////////

#include <iostream>
struct Header{
    unsigned int flag:1;
    bool sig:1;
    unsigned int sn:4;
    unsigned int reserved:2;
    unsigned int crc:8;
};

int main(void){
    Header head = {0};
    head={1,1,0,3,255};   
    head.flag = 1;
    int sz = sizeof(Header);
    std::cout<<"sizeof header="<<sz;
}