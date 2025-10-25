#include <stdarg.h>
#include <iostream>

int sum(int count, ...) {
    int s = 0;
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; ++i) {
        s += va_arg(args, int);
    }
    va_end(args);
    return s;
}

main() {
    std::cout << sum(5, 1, 2, 3, 4, std::string{"13"}) << std::endl; //UB
    return 0;
}