#include <vector>
#include <shared_mutex>
#include <thread>
#include <chrono>
#include <sstream>
#include <iostream>
#include <iomanip>
#include "color.hpp"
using namespace std::chrono_literals;

struct SharedContent
{
    using high_resolution_clock = std::chrono::high_resolution_clock;
    using float_seconds =  std::chrono::duration<float, std::chrono::seconds::period>;
public:
    SharedContent() { startTime = high_resolution_clock::now(); }
    void write()
    {
        std::srand(std::time(nullptr));
        int random_number = std::rand();
        std::stringstream stream;
        stream << "rn=" << random_number << "\n";

        std::lock_guard lock(mtx);
        content = stream.str();
        print(dye::light_green("write"));
        std::this_thread::sleep_for(1s);
    }

    void read()
    {
        std::shared_lock lock(mtx);
        print("read");
        std::this_thread::sleep_for(500ms); // 模拟耗时操作
    }

private:
    float elapsed_time() { return float_seconds(high_resolution_clock::now() - startTime).count(); }
    template<class T> void print(T&& rw){
        std::lock_guard lock2(cout_mtx);
        std::cout<<std::fixed<<std::setprecision(2)<<std::setw(7)<<elapsed_time()<<"s:[tid:" << std::this_thread::get_id() << "]["<<std::setw(5)<<rw<<"] " << content;
    }
private:
    std::shared_mutex mtx;
    std::string content = "no data\n";
    std::mutex cout_mtx;
    high_resolution_clock::time_point startTime;
};

int main(void)
{
    SharedContent content;

    auto read = [&content](){
        for (int i = 0; i < 1000; i++){
            content.read();
            std::this_thread::sleep_for(1ms);
        }
    };

    auto write = [&content](){
        for (int i = 0; i < 1000; i++){
            content.write();
            std::this_thread::sleep_for(1ms);
        }
    };

    std::thread w_th(write);
    std::vector<std::thread> r_threads;
    for (int i = 0; i < 4; i++)
        r_threads.emplace_back(read);

    w_th.join();
    for (auto &t : r_threads)
        t.join();
}