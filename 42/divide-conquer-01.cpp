#include <thread>
#include <vector>
#include <functional>
#include <iostream>
template <typename Iter, typename UnaryOp, typename BinaryOp, typename Result, std::size_t MinDist = 10>
void transform_reduce(Iter first, Iter last, UnaryOp tansform, BinaryOp reduce, Result &res)
{
    std::size_t distance = std::distance(first, last);
    if (distance==1)
    {
            res = reduce(res, tansform(*first));
    }
    else
    {
        std::size_t half = distance / 2;
        Iter middle = first + half;

        Result r_result = 0;
        Result l_result = 0;

        std::thread l_thread(transform_reduce<Iter,UnaryOp,BinaryOp,Result>, first, middle, tansform, reduce, std::ref(l_result));        
        std::thread r_thread(transform_reduce<Iter,UnaryOp,BinaryOp,Result>, middle, last, tansform, reduce, std::ref(r_result));
        
        l_thread.join();
        r_thread.join();
        res = reduce(res,reduce(l_result, r_result));
    }
}

int main(void)
{
    std::vector<double> numbers;
    const int N = 100;
    numbers.reserve(N);
    for (int i = 0; i < N; i++)
    {
        numbers.push_back(i);
    }
    
    double res=0;
    auto transform =  [](double x){return x*x;};
    auto reduce = [](double a,double b){return a + b;};
    
    std::thread thread1(
        transform_reduce<std::vector<double>::iterator,
       decltype(transform),decltype(reduce),double>,numbers.begin(),numbers.end(),transform,reduce,std::ref(res));

    thread1.join();
    std::cout<<res<<std::endl;
}

