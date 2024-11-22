/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 17.类域对象（3）>> 配套例程
// singleton.cpp
// 单例示例
//
/////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

class Singleton {
private:
    static Singleton* m_instance;
    Singleton() {}
    ~Singleton() {}
    
public:
    Singleton(const Singleton& obj) = delete;
    Singleton& operator=(const Singleton&) = delete;

    static Singleton* getInstance() {
        if (!m_instance) 
                m_instance = new Singleton();
        
        return m_instance;
    }
private:
    string m_name;
public:
    void setName(const string& name) { m_name = name;}

    const string& getName() { return m_name;}
};

Singleton* Singleton::m_instance = NULL;

int main(){

    Singleton* s1 = Singleton::getInstance();
    cout<<s1->getName();

    Singleton* s2 = Singleton::getInstance();
    cout<<s1->getName();
}


