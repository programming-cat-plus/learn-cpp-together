#include <thread>
#include <iostream>

void inc(int &res)
{
    for (int i = 0; i < 1000000; i++)
        res++;
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
