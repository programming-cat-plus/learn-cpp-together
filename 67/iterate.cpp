#include <iostream>

template<typename... Ts>
void f(Ts ... args) {
    for(auto v:{float(args)...})
        std::cout<<v<<"\n";
}

int main() {
    f(1, 2.0f, 3.5,4);
    return 0;
}