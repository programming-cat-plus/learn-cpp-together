#include <algorithm>
#include <vector>
#include <iostream>

int main(void)
{
    std::vector<double> numbers{0.5,0.7,3.5,4.6};
    for_each(numbers.begin(),numbers.end(), [](double& v){v = v*v;});
    for(auto number:numbers)
    {
        std::cout<<number<<",";
    }
}

