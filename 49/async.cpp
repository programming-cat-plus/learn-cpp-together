#include <iostream>
#include <future>
#include <chrono>
#include <thread>
#include <iostream>
#include <syncstream>
#include <vector>
#include <numeric>
#include <algorithm>
#include "random_range.h"
#include <map>

float Compute(std::vector<float> &v)
{
    std::this_thread::sleep_for(std::chrono::seconds(2));
    auto r = std::accumulate(v.begin(), v.end(), 0.0f);
    std::osyncstream(std::cout) << "执行任务的线程Id:" << std::this_thread::get_id() << std::endl;
    return r;
}

int main()
{
    const int RN_MAX = 10000;
    Random rgen(0, RN_MAX);
    std::vector<float> numbers(100, 0.0f);
    std::generate(numbers.begin(), numbers.end(), [&]
                  { return float(rgen()) / RN_MAX; }); // Fill the vector with random numbers

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    std::cout << "创建任务的线程Id:" << std::this_thread::get_id() << std::endl;
    std::future<float> result;
    result = std::async(Compute, std::ref(numbers));

    std::this_thread::sleep_for(std::chrono::seconds(2));
    auto r = result.get();
    std::cout << "result =  " << r << std::endl;
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "任务共耗时 = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    return 0;
}

