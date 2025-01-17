/****************************************** 
 * File: 100m-dash.cpp
 * 使用std::latch模拟100米短跑
*/
#include <thread>
#include <latch>
#include <iostream>
#include <array>
#include <algorithm>
#include <chrono>
#include <random>

struct Runner {
    std::string name;   
    int time{0};
    void run(std::latch& start, std::latch& end) 
    {
        //等待发令枪响
        start.wait();
        // 开始跑
        auto start_time = std::chrono::system_clock::now();
        std::mt19937 eng{std::random_device{}()};
        std::uniform_int_distribution<unsigned int> uniform_dist{0, 2000};
        std::this_thread::sleep_for(std::chrono::milliseconds(9600+uniform_dist(eng)));
        auto end_time = std::chrono::system_clock::now();
        time = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
        // 跑完了
        end.count_down(1);
    }
    bool operator<(const Runner& other) const { return time < other.time; }
};

int main() {
    std::vector<Runner> runners = {Runner{"张三"}, Runner{"李四"}, Runner{"王五"}, Runner{"赵六"},Runner{"钱七"}};
    
    const int runner_count = runners.size();
    std::latch start(1);
    std::latch finish(runner_count);
    std::vector<std::thread> threads;
    for (int i=0;i<runner_count;i++) {
        threads.emplace_back(&Runner::run, &runners[i], std::ref(start), std::ref(finish));
    }

    std::cout << "发令枪响" << std::endl;
    start.count_down();

    // 等待所有选手跑完
    finish.wait();

    std::cout << "比赛结果:\n==========================================\n" ;
    std::sort(runners.begin(), runners.end());
    for(auto& runner : runners) {
        std::cout << runner.name << " : " << float(runner.time)/1000 << "秒" <<std::endl;
    }

    for(auto& t : threads) {t.join();}
}
