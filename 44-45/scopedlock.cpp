#include <thread>
#include <iostream>
#include <mutex>

class DemoClass
{
public:
    void func1()
    {
        std::scoped_lock lock(mtx1, cout_mtx);
        count++;
        std::cout << "Count=" << count << "\n";
    }

    void func2()
    {
        std::scoped_lock lock(cout_mtx, mtx1);
        count--;
        std::cout << "Count=" << count << "\n";
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
    std::mutex mtx1;
    std::mutex cout_mtx;
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

