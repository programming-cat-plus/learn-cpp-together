#include <iostream>
#include <vector>
#include <algorithm>

int main(void)
{
    std::vector<int> numbers{1,23,4,5,67,8,67,23,20,11,32,33,45,17};

    auto bound1 = std::partition(numbers.begin(),numbers.end(),[](int v){return v%3==0;});
    auto bound2 = std::partition(bound1,numbers.end(),[](int v){return v%3==1;});
    std::cout<<"\n{x=3k}:\n";
    std::for_each(numbers.begin(),bound1,[](int v){std::cout<<v<<" ";});
    std::cout<<"\n{x=3k+1}:\n";
    std::for_each(bound1,bound2,[](int v){std::cout<<v<<" ";});
    std::cout<<"\n{x=3k+2}:\n";
    std::for_each(bound2,numbers.end(),[](int v){std::cout<<v<<" ";});
}

