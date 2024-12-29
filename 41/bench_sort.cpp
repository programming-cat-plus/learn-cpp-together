#include <parallel/algorithm>
#include <iostream>
#include <numeric>
#include <array>
#include <cmath>
#include <execution>
#include "autotimer.h"

int main(void)
{
    const int N = 100'000'000;
    std::vector<double> numbers;
    numbers.resize(N);
    srand(time(NULL));
    std::generate(numbers.begin(), numbers.end(),
        []() { return (double)rand() / (double)(RAND_MAX); });

    {
        std::vector<double> arr = numbers;
        AutoTimer autotimer("Sequencial Execution");
        std::sort(arr.begin(), arr.end());
    }

    {
        std::vector<double> arr = numbers;
        AutoTimer autotimer("Parallel Execution");
        std::sort(std::execution::par, arr.begin(), arr.end());
    }

    {
        std::vector<double> arr = numbers;
        AutoTimer autotimer("Parallel Unseq Execution");
        std::sort(std::execution::par_unseq, arr.begin(), arr.end());
    }
    return 0;
}
