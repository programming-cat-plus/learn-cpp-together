/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 22.类模板>> 配套例程
// mypair.h
// 模板部分特化示例
//
/////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

//MyPair类主模板
template<typename T1,typename T2>
class MyPair{
private:
    T1 first;
    T2 second;
public:
    MyPair(T1 a, T2 b):first(a),second(b){};
    void print(){
        cout<<"通用类模板"<<endl;
    }
};

//部分特化 MyPair<int,T2>
template<typename T2>
class MyPair<int,T2>{
private:
    int first;
    T2 second;
public:
    MyPair(int a, T2 b):first(a),second(b){};
    void print(){cout<<"部分特化: MyPair<int,T2>"<<endl;}
};

//部分特化 MyPair<T1,float>
template<typename T1>
class MyPair<T1,float>{
private:
    T1 first;
    float second;
    /*..... */
public:
    MyPair(T1 a, float b):first(a),second(b){};
    void print(){cout<<"部分特化: MyPair<T1,float>"<<endl;}
};

//特化实例 MyPair<int,float>
template<>
class MyPair<int,float>{
private:
    int first;
    float second;
    /*..... */
public:
    MyPair(int a, float b):first(a),second(b){};
    void print(){
        cout<<"特化类: MyPair<int,float>"<<endl;
    }
};

//部分特化:指针
template<typename T1,typename T2>
class MyPair<T1*,T2*>{
private:
    T1* first;
    T2* second;
    /*..... */
public:
    MyPair(T1* a, T2* b):first(a),second(b){};
    void print(){
        cout<<"部分特化: MyPair<T1*,T2*>"<<endl;
    }
};