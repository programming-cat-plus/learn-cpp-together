#include <iostream>
int main(void)
{
    auto f = [](auto x, auto y) { return x + y; }; 
    std::cout << "10+20 = " << f(10, 20) << "\n";       
    std::cout << "10.5+20.3 = " << f(10.5, 20.3) << "\n";  ;  
    std::cout << "10+20.3 = " << f(10, 20.3) << "\n";
}