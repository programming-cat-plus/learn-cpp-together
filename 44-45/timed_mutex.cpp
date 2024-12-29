#include <mutex>
#include <thread>
#include <iostream>
#include <sstream>
#include <chrono>

using namespace std::chrono_literals;

class TryDemo
{
public:
    void print(){
        for (int i = 0; i < 10; i++){
            std::unique_lock lock(m_mutex, std::defer_lock);
            if (lock.try_lock_for(100ms)){
                {
                    std::lock_guard guard(cout_mutex);
                    std::cout << "[" << std::this_thread::get_id() << "]" << "成功;\n";
                }

                std::this_thread::sleep_for(100ms);
            }
            else{
                 std::lock_guard guard(cout_mutex);
                 std::cout << "[" << std::this_thread::get_id() << "]" << "失败;\n";
                 std::this_thread::sleep_for(100ms);
            };
        }
    }
private:
    std::timed_mutex m_mutex;
    std::timed_mutex cout_mutex;
    int m_count = 0;
};

int main(void)
{
    TryDemo demo;
    auto print = [](TryDemo &demo)
    { demo.print(); };
    std::thread th1(print, std::ref(demo));
    std::thread th2(print, std::ref(demo));

    th1.join();
    th2.join();
}
