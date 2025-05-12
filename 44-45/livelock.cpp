#include <thread>
#include <iostream>
#include <mutex>
#include <chrono>

using namespace std::chrono_literals;

class DemoClass
{
public:
    void func1(){
        while (true){
            std::unique_lock lock1(mtx1, std::defer_lock);
            std::unique_lock lock2(cout_mtx, std::defer_lock);
            if (!lock1.try_lock_for(100ms))
                continue;
            if (!lock2.try_lock_for(100ms))
                continue;
            count++;
            std::cout << "Count=" << count << "\n";
            break;
        }   
    }

    void func2(){
        while (true){
            std::unique_lock lock1(cout_mtx, std::defer_lock);
            std::unique_lock lock2(mtx1, std::defer_lock);
            if (!lock1.try_lock_for(100ms))
                continue;
            if (!lock2.try_lock_for(100ms))
                continue;
            count++;
            std::cout << "Count=" << count << "\n";
            break;
        } 
    }

    void calc(int n)
    {
        for (int i = 0; i < n; i++)
        {
            if (n % 2)
                func2();
            else
                func1();
        }
    }

private:
    std::timed_mutex mtx1;
    std::timed_mutex cout_mtx;
    int count = 0;
};

int main(void)
{
    DemoClass demo;
    const int N1 = 10000;
    const int N2 = 10001;
    std::thread th1(&DemoClass::calc, &demo, N1);
    std::thread th2(&DemoClass::calc, &demo, N2);

    th1.join();
    th2.join();
}