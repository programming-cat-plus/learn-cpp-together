#include <mutex>
#include <thread>
#include <iostream>

class Counter
{
public:
    void increase(int n)
    {
        std::unique_lock lock(counter_mutex, std::defer_lock);
        while (n--){
            lock.lock();
            m_count++;
            lock.unlock();
        }
    }
    int get()
    {
        std::unique_lock lock(counter_mutex);
        return m_count;
    }
private:
    std::mutex counter_mutex;
    int m_count = 0;
};

int main(void)
{
    Counter counter;
    auto increase = [](Counter &counter)
    {counter.increase(10000); };
    std::thread th1(increase, std::ref(counter));
    std::thread th2(increase, std::ref(counter));

    th1.join();
    th2.join();
    std::cout << "counter=" << counter.get() << "\n";
}


struct adopt_lock_t
{
};

template <typename Mutex>
class lock_guard
{
public:
    explicit lock_guard(Mutex &m) : m_mutex(m)
    {
        m_mutex.lock();
    }
    lock_guard(Mutex &m, adopt_lock_t) noexcept : m_mutex(m) {};

    ~lock_guard()
    {
        m_mutex.unlock();
    }
    lock_guard(const lock_guard &) = delete;
    lock_guard &operator=(const lock_guard &) = delete;

private:
    Mutex &m_mutex;
};
