/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 20.宏定义>> 视频课程 配套例程
// macro.cpp
// 宏定义示例
//
/////////////////////////////////////////////////////////////////

// 简单的宏常量
#define MAX_SIZE 1000
#define NONE_SENSE asdrfa+sddfasf%123

// 简单的宏函数
#define MUL(a,b) a*b

// 在宏函数中使用 字符串符# 和 字符串连接符## 
#define PROPERTY(Type,member) \
    private: \
        Type m_##member;\
    public:\
        const Type& get##member() const{return m_##member;}\
        void set##member(Type m){m_##member = m;}

#define PRINT(a) cout<<#a<<"="<<(a)<<"";
#define MEMBER(type,a) type m_##a


#include <string>
#include <iostream>
using namespace std;

struct Demo{
    MEMBER(int,a);
	MEMBER(int,b);
};


class Example{
    PROPERTY(int, Age)
    PROPERTY(string,Name)
};

int main(void){
    Example obj;
    obj.setName("Tom");
    obj.setAge(12);
    cout<<obj.getName()<<endl;

    float a=3.0;
    PRINT(a*2+3);
}