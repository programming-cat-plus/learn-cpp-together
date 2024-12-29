#include <iostream>
#include <type_traits>

template <class T>
void testIntegral(T a)
{
    if (std::is_integral<T>::value){
        std::cout <<std::boolalpha<< a << " IS an integral type" << std::endl;
    }
    else{
        std::cout << a << " is NOT an integral type" << std::endl;
    }
}

int main(void)
{
    testIntegral(3);
    testIntegral(false);
    testIntegral('A');
    testIntegral(3.5);
    //testIntegral("Abc");
    testIntegral(30L);
    int a = 10;
    int& b =a;
    testIntegral(b);
    std::cout <<std::boolalpha<< std::is_integral<int&>::value << std::endl;
}





