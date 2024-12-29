#include <iostream>
#include <vector>

template<typename T, typename P> 
std::vector<T> Filter(const std::vector<T>& vec, P pred)
{
    std::vector<T> res;
    for(auto s:vec)
    {
        if(pred(s))
            res.push_back(s);
    }
    return res;
}

int main(void)
{
    std::string word="apple";
    auto hasWord = [&word](std::string& s){return s.find(word)!=s.npos;};
    std::vector<std::string> words{"An apple","big apple","orange","green apple","grape"};
    std::vector<std::string> res = Filter(words,hasWord);

    for(auto s:res)
        std::cout<<s<<" "<<std::endl;
}