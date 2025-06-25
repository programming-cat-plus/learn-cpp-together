#include <regex>
#include <string>
#include <iostream>
#include "color.hpp"

void test(std::string pattern, std::string text) {
    std::regex re(pattern);
    std::sregex_iterator it(text.begin(), text.end(), re);
    std::sregex_iterator end;

    unsigned int nextpos = 0;
    while (it != end) {
        std::smatch match = *it;
        for(unsigned int i = 0; i < match.size(); ++i) {
            if(match.size()>1&&i==0)
                continue; // Skip the full match, only print submatches
            auto regstart = it->position(i);
            std::cout<<text.substr(nextpos, regstart-nextpos);
            std::cout<<dye::on_light_blue(it->str(i));
            nextpos = regstart + it->length(i);           
        }
        ++it;
    }
    std::cout<<text.substr(nextpos, text.length())<<std::endl;
}
int main() {
    std::string text = "The event begins in 2025-6-30, and ends in 2025-12-01, and 2025-12-01 is the deadline.";
    test("(\\d{4})-([01]?\\d)-([0-3]?\\d)", text);

    test("event", text);
}