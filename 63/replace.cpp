#include <regex>
#include <string>
#include <iostream>
#include "color.hpp"

int main(void)
{
    std::vector<std::string> texts = {"2025-12-01", "01-01-2025", "2025-30-02", "start: 2025-9-1, end: 2025-12-01"};

    std::regex re("(\\d{4})-([01]?\\d)-([0-3]?\\d)");
    for (auto t : texts)
    {
        auto out = std::regex_replace(t, re,"$1年$2月$3日");
        std::cout << dye::light_aqua(t) << " => \n";            
        std::cout << dye::purple(out) << "\n\n";    
    }
    return 0;
}