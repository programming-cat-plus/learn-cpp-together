#include <string>
#include <iostream>
const char* catportrait = ""
"  /\\_/\\  (\n"
" ( ^.^ ) _)\n"
"   \\\"/  (\n"
" ( | | )\n"
"(__d b__)\n";

template<char... t>
std::string operator""_cat() {
    return std::string("\033[0m\033[1;")+std::string({t...})+("m")+std::string{catportrait} + "\033[0m";
}

int main() {
    std::cout << 31_cat << std::endl;
    std::cout << 32_cat << std::endl;
    std::cout << 33_cat << std::endl;
    return 0;
}
