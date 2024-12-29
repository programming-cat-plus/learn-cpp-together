#include <iostream>
#include <type_traits>

template<typename T>
void isInt(T&& a)
{
    if(std::is_same<T,int>::value)
    {
        std::cout<<"It is  INT\n";
    }
}

int main(void)
{
    int a = 3;
    int&& b = 5;
    isInt(a);
    isInt(int(5));
}