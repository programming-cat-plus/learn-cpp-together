#include <mutex> 
#include <thread>
#include <iostream>

class Counter{
public:
    void inc()
    {
        counter_mutex.lock();
        m_count++;
        counter_mutex.unlock();
    } 
    int get(){
        int temp;
        counter_mutex.lock();
        temp = m_count;
        counter_mutex.unlock();
        return temp;
        }
private:
    std::mutex counter_mutex;
    int m_count = 0;
};

int main(void){
    Counter counter;
    auto increase = [](Counter& counter){for(int i=0;i<1000000;i++)counter.inc();};
    std::thread th1(increase, std::ref(counter));
    std::thread th2(increase, std::ref(counter));

    th1.join();
    th2.join();

    std::cout << "counter=" << counter.get() << "\n";
}
