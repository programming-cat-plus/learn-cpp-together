#include <iostream>
#include <atomic>
#include <thread>
#include <assert.h>
#include <mutex>

class SpinLock {
public:
    void lock() {
        while (flag.test_and_set(std::memory_order_acquire)) {}
    }
    
    void unlock() {
        flag.clear(std::memory_order_release);
    }
private:
    std::atomic_flag flag{ATOMIC_FLAG_INIT};
};

int main(void)
{
    SpinLock spin;
    int count = 0;
    
    auto inc = [&]() {
        for (int i = 0; i < 1000; ++i) {
            std::lock_guard<SpinLock> lock(spin);
            ++count;
        }
    };
    
    std::thread t1(inc);
    std::thread t2(inc);
    
    t1.join();
    t2.join();
    std::cout << "Count: " << count << std::endl;
}
