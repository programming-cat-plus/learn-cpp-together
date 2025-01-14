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
    std::generate(numbers.begin(), numbers.end(), [&] { return float(rgen()) / RN_MAX; }); // Fill the vector with random numbers
    
    std::cout << "创建任务的线程Id:"<<std::this_thread::get_id()<< std::endl;

    std::packaged_task<float(std::vector<float>&)> task(Compute);
    
    std::cout<<"*****************直接调用********************"<<std::endl;
    std::future<float> result = task.get_future();
    task(numbers);
    std::cout<<"Result="<<result.get()<<std::endl;

    task.reset();

    std::cout<<"*****************使用线程调用******************"<<std::endl;
    result = task.get_future();
    std::thread t(std::move(task),std::ref(numbers));
    std::cout<<"Result="<<result.get()<<std::endl;
    t.join();
    return 0;
}
