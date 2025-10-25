#include <vector>
#include <set>
#include <iostream>
#include <concepts>

template<typename Container, typename... Args>
void batch_insert(Container& c, Args&&... args) {
    (c.insert(c.end(), std::forward<Args>(args)), ...);
}

int main() {
    std::vector<int> vec;
    batch_insert(vec, 1, 2, 3, 4, 5,5);

    for (const auto& v : vec) {
        std::cout << v << " "; // Outputs: 1 2 3 4 5, 5
    }
    std::cout << std::endl;

    std::set<int> s;
    batch_insert(s, 1, 2, 3, 4, 5,5);

    for (const auto& v : s) {
        std::cout << v << " "; // Outputs: 1 2 3 4 5, 5
    }
    std::cout << std::endl;

    return 0;
}