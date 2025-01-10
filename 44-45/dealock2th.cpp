#include <thread>
#include <iostream>
#include <mutex>
using namespace std::chrono_literals;

class DemoClass
{
public:
    void func1(){
        {
            std::lock_guard lock1(mtx1);
            std::lock_guard lock2(cout_mtx);
            count++;
            std::cout << "[func1]Count=" << count << "\n";
        }
        std::this_thread::sleep_for(1ms);
    }
    void func2(){
        {
            std::lock_guard lock1(cout_mtx);
            std::lock_guard lock2(mtx1);
            count--;
            std::cout << "[func2]Count=" << count << "\n";
        }
        std::this_thread::sleep_for(1ms);
    }
    void calc(int n){
        for (int i = 0; i < n; i++){
            if (n % 2)
                func2();
            else
                func1();
        }
    }
private:
    std::mutex mtx1;
    std::mutex cout_mtx;
    int count = 0;
};

int main(void)
{
    DemoClass demo;
    const int N1 = 10000;
    const int N2 = 10001;
    std::thread th1(DemoClass::calc, &demo, N1);
    std::thread th2(DemoClass::calc, &demo, N2);

    th1.join();
    th2.join();
}