#include <iostream>
#include <stdexcept>
#include <future>

void divide(double a, double b, std::promise<double> &&pr)
{
    try
    {
        if (b == 0)
            throw std::runtime_error("被0除异常");
        pr.set_value(a / b);
    }
    catch(...){
        pr.set_exception(std::current_exception());
    }
}

int main(void){
    std::promise<double> promise;
    auto future = promise.get_future();
    double a = 13, b = 0;

    std::thread th(divide, a, b, std::move(promise));
    try{    
        auto result = future.get();
        std::cout << "result=" << result << "\n";
    }
    catch (std::runtime_error &e){
        std::cout << e.what() << "\n";
    }
    th.join();
}
