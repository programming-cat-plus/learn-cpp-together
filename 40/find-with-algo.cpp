#include <iostream>
#include <vector>
#include <algorithm>

template<typename T, typename P> 
std::vector<T> Filter(const std::vector<T>& vec, P pred)
{
    std::vector<T> res;
    std::copy_if(vec.begin(),vec.end(),std::back_inserter(res),pred);
    return res;
}

int main(void)
{
    std::string word="apple";
    auto hasWord = [&word](const std::string& s){return s.find(word)!=s.npos;};
    std::vector<std::string> words{"An apple","big apple","orange","green apple","grape"};
    std::vector<std::string> res = Filter(words,hasWord);

    for(auto s:res)
        std::cout<<s<<" "<<std::endl;
}