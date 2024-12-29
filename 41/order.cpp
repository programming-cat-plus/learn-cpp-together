#include <algorithm>
#include <iostream>
#include <execution>
#include <vector>

int main(void)
{
    auto op = [](int v){std::cout<<v<<";\n";}; 
    std::vector<int> numbers{1,2,3,4,5,6,7,8,9};

    std::cout<<"==============sequential for_each===============\n";
    std::for_each(std::execution::seq,numbers.begin(), numbers.end(),op);
    std::cout<<"==============parallel for_each===============\n";
    std::for_each(std::execution::par,numbers.begin(), numbers.end(),op);
    std::cout<<"==============parallel unseq for_each===============\n";
    std::for_each(std::execution::par_unseq,numbers.begin(), numbers.end(),op);
}