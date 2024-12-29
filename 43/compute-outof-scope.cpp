#include <future>
#include <iostream>

void compute_pi(const long num_steps, std::promise<double> &promise)
{
    double step = 1.0 / num_steps;
    double sum = 0.0;
    for (long i = 0; i < num_steps; i++)
    {
        double x = (i + 0.5) * step;
        sum += 4.0 / (1.0 + x * x);
    }
    promise.set_value(sum * step);
}

void display(std::future<double> &receiver)
{
    double pi = receiver.get();
    std::cout << "返回值=" << pi << std::endl;
};

int main(void)
{
    const int N_STEPS = 1000000000;
    std::thread th1;
    std::thread th2;
    {
        std::promise<double> promise;
        auto receiver = promise.get_future();
        th1 = std::thread(compute_pi, N_STEPS, std::ref(promise));
        th2 = std::thread(display, std::ref(receiver));
    }
    th1.join();
    th2.join();
}

