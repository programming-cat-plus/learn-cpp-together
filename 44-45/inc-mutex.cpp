#include <mutex>
#include <thread>
#include <iostream>
 

std::mutex counter_mutex;
void inc(int &res)
{
    for (int i = 0; i < 1000000; i++)
    {
        counter_mutex.lock();
        res++;
        counter_mutex.unlock();
    }
        
}

int main(void)
{
    int counter = 0;
    std::thread th1(inc, std::ref(counter));
    std::thread th2(inc, std::ref(counter));

    th1.join();
    th2.join();

    std::cout << "counter=" << counter << "\n";
}
