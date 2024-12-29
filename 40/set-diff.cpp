#include <iostream>
#include <vector>
#include <algorithm>

int main(void)
{
    std::vector<int> numbers1{1,1,2,3,4,4,5,6};
    std::vector<int> numbers2{9,8,7,6,5,5,4};
    std::vector<int> result;

    std::sort(numbers1.begin(),numbers1.end());
    std::sort(numbers2.begin(),numbers2.end());

    std::set_difference(numbers1.begin(),numbers1.end(),
                        numbers2.begin(),numbers2.end(),
                        std::back_insert_iterator(result));
    for(auto v:result)
        std::cout<<v<<" ";
}


