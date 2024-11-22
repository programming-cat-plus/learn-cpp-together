#include <iostream>
using namespace std;

void f(const string& s){
    cout<<"左值:"<<s<<endl;
}

void f(string&& s){
    cout<<"右值:"<<s<<endl;
}

void f(const string& s1,const string& s2){
    cout<<"左值:"<<s1<<","<<s2<<endl;
}

void f(const string&& s1,const string&& s2){
    cout<<"左值:"<<s1<<","<<s2<<endl;
}

#define FORWARD 2
#if FORWARD==0
void g(const string& s){
    f(s);
}
void g(string&& s){
    f(s);
}
#elif FORWARD==1
void g(const string& s){
    f(static_cast<const string&>(s));
}
void g(string&& s){
    f(static_cast<string&&>(s));
}
#else
void g(const string& s){
    f(std::forward<const string&>(s));
}
void g(string&& s){
    f(std::forward<string&&>(s));
}
#endif

int main(void)
{
    g(string("Hello1"));
    string s("hello2");
    g(s);
}