#include "is_arithmetic.h"
#include <iostream>

#define TEST(T) is_arithmetic<T>::value?std::cout<<#T<<" is arithmetic"<<"\n":std::cout<<#T<<" is NOT arithmetic"<<"\n";

int main(void)
{
    TEST(int)
    TEST(std::string)
    TEST(double)
    TEST(long)
    TEST(char)

}