#include <atomic>
#include <thread>
#include <iostream>

int fetch_multiply_err(std::atomic<int> &value, int multiplier)
{
    int oldValue = value.load();
    int newValue{oldValue * multiplier%1000};
    value.store(newValue);
    return oldValue;
}

int fetch_multiply(std::atomic<int> &value, int multiplier)
{
    int oldValue = value.load();
    int desired;
    do
    {
        desired = oldValue * multiplier;
    }while(!value.compare_exchange_strong(oldValue, desired));

    return oldValue;
}

int main(void)
{
    std::atomic<int> value = 1;
    auto l = [&value](int m,int n,int duration){
        for(int i=0;i<n;i++)
        {
            fetch_multiply(value,m);
            std::this_thread::sleep_for(std::chrono::milliseconds(duration));
        }
    };

    std::thread th1(l,1,1000,0);
    std::thread th2(l,2,16,1000);
    th1.join();
    th2.join();
    std::cout<<value;
}