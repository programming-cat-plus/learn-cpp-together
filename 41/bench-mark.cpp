#include <algorithm>
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
        AutoTimer autotimer("transform reduce:Sequencial:");
        auto avg = std::accumulate(arr.begin(), arr.end(), 0.0) / N;

        auto result = std::transform_reduce(std::execution::seq, arr.begin(), arr.end(), 0.0, [](auto first, auto second)
            { return first + second; }, [avg](auto val)
            { auto t = val - avg; return t * t; }) / N;
        std::cout << "result=" << result << std::endl;
    }

    {
        
        std::vector<double> arr = numbers;
        AutoTimer autotimer("transform reduce:Parallel");
        auto avg = std::reduce(std::execution::par, arr.begin(), arr.end(), 0.0) / N;

        auto result = std::transform_reduce(std::execution::par, arr.begin(), arr.end(), 0.0, [](auto first, auto second)
            { return first + second; }, [avg](auto val)
            { auto t = val - avg; return t * t; }) / N;
        std::cout << "result=" << result << std::endl;
    }

    {
        
        std::vector<double> arr = numbers;
        AutoTimer autotimer("transform reduce:Parallel Unseq");
        auto avg = std::reduce(std::execution::par_unseq, arr.begin(), arr.end(), 0.0) / N;

        auto result = std::transform_reduce(std::execution::par_unseq, arr.begin(), arr.end(), 0.0, [](auto first, auto second)
            { return first + second; }, [avg](auto val)
            { auto t = val - avg; return t * t; }) / N;
        std::cout << "result=" << result << std::endl;
    }
    return 0;
}
