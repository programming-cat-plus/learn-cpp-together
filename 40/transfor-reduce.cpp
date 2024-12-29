#include <algorithm>
#include <iostream>
#include <numeric>
#include <array>
#include <cmath>

int main(void)
{
    const int N = 10000;
    std::array<double, N> numbers;
    std::generate(numbers.begin(), numbers.end(), 
                    [](){ return (double)rand() / (double)(RAND_MAX); });

    auto avg = std::accumulate(numbers.begin(), numbers.end(), 0.0)/N;

    auto result = std::transform_reduce(numbers.begin(), numbers.end(), 0.0, 
                                        [](auto first, auto second)
                                        { return first + second; }, 
                                        [avg](auto val)
                                        { auto t = val-avg; return t*t; })/N;
    std::cout << "result=" << result << std::endl;
}

