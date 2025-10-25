#include <memory>
#include <iostream>
#include <type_traits>
#include "value_cateory.h"

auto f(auto&& arg) {
    std::cout<< (std::is_lvalue_reference_v<decltype(arg)> ? "lvalue:" : "rvalue:") << arg << std::endl;
}

auto g(auto && arg) {
    return f(std::forward<decltype(arg)>(arg));
}

int main() {
    std::string s = "hello";
    g(s);        // lvalue passed
    g(std::string("hello"));       // rvalue passed
}

