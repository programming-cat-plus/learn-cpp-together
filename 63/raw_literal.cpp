#include <regex>
#include <string>
#include <iostream>
#include "color.hpp"

int main(void)
{
    std::vector<std::string> texts = {"2025-12-01", "01-01-2025", "2025-30-02", "dealine is 2025-12-01"};

    std::regex re(R"((\d{4})-([01]\d)-([0-3]\d))");
    std::smatch m;
    for (auto t : texts)
    {
        if (std::regex_match(t, m, re))
        {
            std::cout << dye::light_aqua(t) << " matches the pattern." << std::endl;
            for (int i=0;i<m.size();i++)
            {
                std::cout << "\tMatch[" <<i<<"]:"<<  dye::light_aqua(m[i]) << std::endl;
            }
        }
        else
            std::cout << dye::yellow(t) << " does not match the pattern." << std::endl;
    }
    return 0;
}