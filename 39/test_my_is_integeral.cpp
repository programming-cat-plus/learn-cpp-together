#include <iostream>
#include "my_is_integral_v3.h"

int main(void)
{
    std::cout<<std::boolalpha;
    std::cout<<my_is_integral<int>::value<<std::endl;
    std::cout<<my_is_integral<float>::value<<std::endl;
    std::cout<<my_is_integral<const int>::value<<std::endl;
}