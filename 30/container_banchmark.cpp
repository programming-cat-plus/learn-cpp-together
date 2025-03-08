/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 30.智能指针:unique_ptr>> 配套例程
// container_banchmark.cpp
// 对象、指针和unique_ptr性能比较示例
// 本示例要求编译器使用的C++标准：C++17以上
//
/////////////////////////////////////////////////////////////////

#include <memory>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <chrono>
#include <iostream>

using namespace std;
using namespace std::chrono;

struct Packet{
    Packet(long id):m_id(id){};
    long m_id; 
    char Data[1000];
};

struct Compare{ 
    bool operator()(const Packet& a,const Packet& b){
        return a.m_id<b.m_id;
    }
    bool operator()(const Packet* pA, const Packet* pB){
        return pA->m_id<pB->m_id;
    }

    template<template<typename> typename SmartPtr>
    bool operator()(const SmartPtr<Packet>& pA, const SmartPtr<Packet>& pB){
        return pA->m_id<pB->m_id;
    }
};

class AutoTimer{
private:
    high_resolution_clock::time_point startTime;
    string description;
public:
    AutoTimer(const char* desc):description(desc){ startTime = high_resolution_clock::now();};
    ~AutoTimer(){
        high_resolution_clock::time_point endTime = high_resolution_clock::now();
        auto duration = duration_cast<std::chrono::microseconds>(endTime - startTime).count();
        cout<<description<<":"<<duration<<" ms"<<endl;
    }
};

void sortValueVector(vector<int> ids){
    vector<Packet> vecPacket;
    for(auto id:ids)
    {
        vecPacket.push_back(Packet(id));
    }

    {
        AutoTimer autoTimer("sortValueVector");
        sort(vecPacket.begin(),vecPacket.end(),Compare());
    }
};

void sortPointerVector(vector<int> ids){
    vector<Packet*> vecPacket;
    for(auto id:ids)
    {
        vecPacket.push_back(new Packet(id));
    }

    {
        AutoTimer autoTimer("sortPointerVector");
        sort(vecPacket.begin(),vecPacket.end(),Compare());
    }
};

template<typename SmartPtr>
void sortSmartPtrVector(vector<int> ids){
    vector< SmartPtr > vecPacket;
    for(auto id:ids)
    {
        vecPacket.push_back(SmartPtr(new Packet(id)));
    }

    { 
        AutoTimer autoTimer("sortUniqPtrVector");
        sort(vecPacket.begin(),vecPacket.end(),Compare());
    }
}


int main(){
    int n = 10000;
    vector<int> randomId(n,0);
    srand(time(0));
    for(int i=0;i<n;i++)
        randomId[i] = rand()%100000;

    sortValueVector(randomId);
    sortPointerVector(randomId);
    sortSmartPtrVector<unique_ptr<Packet>>(randomId);
}
