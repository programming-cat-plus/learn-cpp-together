#include <cstring>
#include <iostream>
#include <type_traits>
#include <array>
class A{};

class NonTrivialB
{
public:
    NonTrivialB(int a, int b) : m_a(a), m_b(b) {}
    NonTrivialB() = default;
    virtual ~NonTrivialB() {};
    virtual void print() { std::cout << "a=" << m_a << ", b=" << m_b << ", s="<<"\n"; }
    int m_a = 0;
private:
    int m_b = 5;
    //std::string m_s{"aaa"};
};

struct TrivialA
{
public:
    int m_a;
    TrivialA(int a, int b) : m_a(a), m_b(b) {};
    TrivialA() = default;
    TrivialA& operator=(const TrivialA&)=default;
    void print() { std::cout << "a=" << m_a << ", b=" << m_b << "\n"; }
private:
    int m_b;
};

struct Trivial2
{
   int i;
   Trivial2(int a, int b) : i(a), j(b) {}
   Trivial2() = default;
private:
   int j;   // Different access control
};

struct AA{
    int a;
    int b;
    int c;
    int sum(){
        return a+b+c;
    }
};
template<class T>
void printType()
{
    std::cout<<"Info of class "<<typeid(T).name()<<":\n";
    std::cout<<"  Size of class="<<sizeof(T)<<"\n";
    std::cout<<"  Is trivial="<<std::boolalpha<<std::is_trivial_v<T><<"\n";
    std::cout<<"  Is trivial copyable="<<std::boolalpha<<std::is_trivially_copyable<T>::value<<"\n";
    std::cout<<"  Is standard layout="<<std::boolalpha<<std::is_standard_layout<T>::value<<"\n";
}
template<class T>
void copyTest(T* dst, T* src) {
    std::memcpy(dst, src, sizeof(T));
}



int main(void)
{

    {
        NonTrivialB obj1(10, 2);
        NonTrivialB obj2;
        //std::memmove(&obj2, &obj1, sizeof(obj1));
        obj2.print();
        printType<NonTrivialB>();
    }

    {
        TrivialA obj1;//(10, 2);
        TrivialA obj2;//(3,1);
        //std::memmove(&obj2, &obj1, sizeof(obj1));
        //obj2.print();
        printType<TrivialA>();
    }
    {
        printType<A>();
    }

    {
        printType<Trivial2>();
    }

    {
        TrivialA obj1(10, 2);
        TrivialA obj2;
        const size_t n = sizeof(TrivialA);
        char buffer[n]={};
        std::memcpy(buffer,&obj1,n);
        std::memcpy(&obj2,buffer,n);
        obj2.print();
    }

    {
        NonTrivialB obj1(10,11);
        NonTrivialB obj2;
        copyTest(&obj2,&obj1);
        obj2.print();
    }

{
    std::array<int,5> s={};
    s[3] = 11;
}
{
    std::cout<<std::boolalpha;
    std::cout<<std::is_standard_layout<TrivialA>::value<<"\n";
}
}