#include <iostream>

auto add(auto a,auto b){
    return a+b;
};

void
printall(const auto &...args)
{
    (std::cout << ... << args);
}

int main() {
    printall("Sum of 10 and 20 is: ", add(10, 20), "\n");
    printall("Sum of 5.5 and 3.2 is: ", add(5.5, 3.2), "\n");
    printall("Sum of 5.1 and 2 is: ", add<float,int>(5.1, 2), "\n");
    return 0;
}
