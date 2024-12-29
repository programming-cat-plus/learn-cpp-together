#include <future>
#include <iostream>

void compute_pi(const long num_steps,std::promise<double>&& promise)
{
    double step = 1.0 / num_steps;
    double sum = 0.0;
    for (long i = 0; i < num_steps; i++){
        double x = (i + 0.5) * step;
        sum += 4.0 / (1.0 + x * x);
    }
    promise.set_value(sum * step);
}

int main(void)
{
    const int  N_STEPS = 1000000000;
    std::promise<double> promise;
    auto receiver = promise.get_future();
    std::thread th(compute_pi,N_STEPS,std::move(promise));
    double pi = receiver.get();
    std::cout<<"返回值="<<pi<<std::endl;
    th.join();
}
