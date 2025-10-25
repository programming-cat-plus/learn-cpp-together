#include <iostream>

auto add(auto a,auto b){
    return a+b;
};


int main() {
    std::cout << "Sum of 10 and 20 is: " << add(10, 20) << std::endl;
    std::cout << "Sum of 5.5 and 3.2 is: " << add(5.5, 3.2) << std::endl; 
    std::cout << "String Concatenation:" << add(std::string("apple"), std::string("banana")) << "\n";      
    std::cout << "Sum of 5.1 and 2 is: " << add<float,int>(5.1, 2) << std::endl;
    return 0;
}




