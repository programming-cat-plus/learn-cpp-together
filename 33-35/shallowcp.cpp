/********************************
shallowcp.cp
浅拷贝的错误示例
********************************/

#include <iostream>
using namespace std;

class CharBuffer
{
public:
    CharBuffer():m_buff(nullptr),m_Size(0){
        cout<<"默认构造函数"<<endl;
    };
    CharBuffer(unsigned int nSize):m_buff(new char[nSize]){
        cout<<"普通构造函数"<<endl;
    }

    ~CharBuffer(){ 
        if(m_buff)
            delete[] m_buff; 
        cout<<"析构函数"<<endl;
    }
private:
    char* m_buff;
    unsigned int m_Size;
};

int main(){
    CharBuffer buf1(100);
    CharBuffer buf2(buf1);
}