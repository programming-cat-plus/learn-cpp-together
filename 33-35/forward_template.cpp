#include <iostream>
using namespace std;

void f(const string& s){
    cout<<"左值:"<<s<<endl;
}

void f(string&& s){
    cout<<"右值:"<<s<<endl;
}

template<class T>
void g(T&& v)
{
    f(std::forward<T>(v));
}

int main(void)
{
    g(string("Hello1"));
    const string s("hello2");
    g(s);
}