#include <iostream>
#include <vector>
struct S
{
    float a;
};

int main(void)
{
    {
        int a;
        decltype(a) b;
    }
    {
        const int a = 3;
        decltype(a) b = 5;
    }
    {
        int a = 3;
        int& b = a;
        decltype(b) c = a;
        std::cout<<"before: a = "<<a<<"\n";
        c = 4;
        std::cout<<"after:  a = "<<a<<"\n";
    }

    {
        decltype(S::a) a = 0.1;
    }

    {   
        S s1;
        decltype(s1.a) a = 0.1;
    }

    {
        const int a = 3;
        const int& b = a;
        decltype(b) c = b;
        auto d = b;
        const auto& e = b;
        decltype(auto) f = b;
    }
}