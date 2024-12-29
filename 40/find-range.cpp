#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>
int main(void)
{
    std::string word="apple";
    auto hasWord = [&word](const std::string& s){return s.find(word)!=s.npos;};
    std::vector<std::string> words{"An apple","big apple","orange","green apple","grape"};
    std::vector<std::string> res; 
    
    std::ranges::copy_if(words,std::back_inserter(res),hasWord);

    for(auto s:res)
        std::cout<<s<<" "<<std::endl;
}

