#include <memory>
#include <string>
class TrivialA
{
public:
    TrivialA(int a) : m_a(a) {};
    TrivialA(const TrivialA &other) : m_a(other.m_a) {};

private:
    int m_a{1};
    TrivialA() = delete;
    std::string m_name;
};

main()
{
    float a = 10;

    {
        TrivialA obj1(10);
        TrivialA obj2{obj1};
        TrivialA obj3 = obj1;
    }
    {
        TrivialA obj1(10);
        TrivialA obj2;
        obj2 = obj1;
    }
}