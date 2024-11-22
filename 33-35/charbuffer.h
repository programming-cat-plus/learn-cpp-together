#pragma once
#include <iostream>

class CharBuffer
{
public:
    CharBuffer():m_buff(nullptr),m_Size(0){
        std::cout<<"默认构造函数"<<std::endl;
    }

    CharBuffer(unsigned int nSize):m_buff(new char[nSize]),m_Size(nSize){
        std::cout<<"普通构造函数"<<std::endl;
    }

    CharBuffer(const CharBuffer& other):m_Size(other.m_Size),m_buff(new char[m_Size])
    {
        memcpy(m_buff,other.m_buff,m_Size);
        std::cout<<"拷贝构造函数"<<std::endl;
    }

    CharBuffer& operator=(const CharBuffer& other){
        if(this==&other)
            return *this;

        m_Size = other.m_Size;
        delete[] m_buff;
        m_buff = new char[m_Size];
        memcpy(m_buff,other.m_buff,m_Size);
        std::cout<<"拷贝赋值运算符"<<std::endl;
        return *this;
    }

    CharBuffer(CharBuffer&& other):m_Size(other.m_Size),m_buff(other.m_buff)
    {
        other.m_buff = nullptr;
        other.m_Size = 0;
        std::cout<<"移动构造函数"<<std::endl;
    }

    CharBuffer& operator=(CharBuffer&& other){
        if(this==&other)
            return *this;

        delete[] m_buff;
        m_Size = other.m_Size;
        m_buff = other.m_buff;

        other.m_Size = 0;
        other.m_buff = nullptr;
        std::cout<<"移动赋值运算符"<<std::endl;
        return *this;
    }

    ~CharBuffer(){ 
        delete[] m_buff; 
        std::cout<<"析构函数"<<std::endl;
    }
private:
    char* m_buff;
    unsigned int m_Size;
};
