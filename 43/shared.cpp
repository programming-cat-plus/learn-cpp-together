#include <future>
#include <iostream>
#include <sstream>

void compute_pi(const long num_steps, std::promise<double>&& promise){
    double step = 1.0 / num_steps;
    double sum = 0.0;
    for (long i = 0; i < num_steps; i++)
    {
        double x = (i + 0.5) * step;
        sum += 4.0 / (1.0 + x * x);
    }
    promise.set_value(sum * step);
}

void display(std::shared_future<double> receiver){
    static std::mutex mu;
    double pi = receiver.get();
    printf("返回值=%f\n",pi);
};

int main(void){
    const int N_STEPS = 1000000000;

    std::promise<double> promise;
    //std::shared_future<double> shared_receiver(promise.get_future());
    auto receiver = promise.get_future();
    auto shared_receiver = receiver.share();
    std::thread th1(compute_pi, N_STEPS, std::move(promise));
    std::thread th2(display, shared_receiver);
    std::thread th3(display, shared_receiver);
    
    th1.join();
    th2.join();
    th3.join();
}

