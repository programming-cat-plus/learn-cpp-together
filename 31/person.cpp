/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 31.智能指针:shared_ptr和weak_ptr>> 配套例程
// person.cpp
// shared_ptr循环引用示例
//
/////////////////////////////////////////////////////////////////

#include <iostream>
#include <memory>
#include <vector>
using namespace std;
#define USE_WEAk 1 //改为1时使用weak_ptr，解除循环引用

class Person{
public:
    Person(const string &name):_name(name){cout<<_name<<" constructed"<<endl;}
    ~Person(){cout<<_name<<" destructed"<<endl;}
    void setPartner(const shared_ptr<Person>& other){_partner = other;};
private:
    string _name;

#if USE_WEAk==1
    weak_ptr<Person> _partner;
#else
    shared_ptr<Person> _partner;
#endif
};

int main(void){
    vector< shared_ptr<Person> > people;
    people.push_back(shared_ptr<Person>(new Person("张三")));
    people.push_back(shared_ptr<Person>(new Person("李四")));
    people.push_back(shared_ptr<Person>(new Person("王五")));
    people[0]->setPartner(people[1]);
    people[1]->setPartner(people[2]);
    people[2]->setPartner(people[0]);
    return 0;
}