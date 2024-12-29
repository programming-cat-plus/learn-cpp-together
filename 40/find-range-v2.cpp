#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>

int main(void)
{
    std::string word="apple";
    auto hasWord = [&word](const std::string& s){std::cout<<"pred called\n";return s.find(word)!=s.npos;};
    std::vector<std::string> words{"An apple","big apple","orange","green apple","grape"};
    
    auto res = words | std::views::filter(hasWord); 
    std::cout<<"=====================filter view object created=====================\n";
    
    for(auto s:res)
        std::cout<<s<<" "<<std::endl;

}


