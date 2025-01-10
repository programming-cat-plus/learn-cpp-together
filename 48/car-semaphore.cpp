/*************************************************
 *
 *     使用信号量解决停车场问题
 * 
 ************************************************/
#include <vector>
#include <array>
#include <iostream>
#include <sstream>
#include <syncstream>
#include <mutex>
#include <semaphore>
#include <thread>
#include <chrono>
#include "random_range.h"

template <std::size_t N = 10>
class CarPark
{
public:
    CarPark() : sem(N) {};
    int enter(){
        std::osyncstream(std::cout)<<"["<<std::this_thread::get_id()<<"]准备进入停车场\n";
        sem.acquire();
        std::lock_guard lock(mtx);
        std::osyncstream(std::cout)<<"["<<std::this_thread::get_id()<<"]\t进入停车场\n";
        for (int i = 0; i < N; i++)
        {
            if (spaces[i].empty())
            {
                std::stringstream ss;
                ss << std::this_thread::get_id();
                spaces[i] = ss.str();
                std::osyncstream(std::cout)<<"["<<std::this_thread::get_id()<<"]\t\t找到#"<<i<<"号车位\n";
                return i;
            }
        }
        throw(std::runtime_error("程序异常到达此处！"));
    }

    void do_something(){std::this_thread::sleep_for(std::chrono::milliseconds(rn.generate())); }

    void leave(int idx){
        std::osyncstream(std::cout)<<"["<<std::this_thread::get_id()<<"]\t\t\t离开#"<<idx<<"号车位\n";
        {
            std::lock_guard lock(mtx);
            spaces[idx].clear();
        }
        sem.release();
    }

    void enter_and_leave(){
        int spaceId = enter();
        do_something();
        leave(spaceId);
    }

private:
    std::array<std::string, N> spaces;
    std::counting_semaphore<N> sem;
    std::mutex mtx;
    Random rn{500, 5000};
};

int main(void)
{
    const int NSpaces = 10;
    const int NCars   = 100;
    CarPark<NSpaces> park;
    std::vector<std::thread> cars;
    for (int i = 0; i < NCars; i++){
        cars.emplace_back(
            [&park](){park.enter_and_leave();});
    }

    for (auto &t : cars)
        t.join();
}
