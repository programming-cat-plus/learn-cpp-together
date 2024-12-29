#include <thread>
#include <vector>
#include <array>
#include <iostream>

template <typename Iter, typename UnaryOp, typename BinaryOp, typename Result>
void transform_reduce(Iter first, Iter last, UnaryOp tansform, BinaryOp reduce, Result &res)
{    
    for(auto it=first;it<last;it++)
    {
        res = reduce(res,tansform(*it));
    }
}


int main(void)
{   
    const int N = 10000;
    std::vector<double> numbers;
    numbers.reserve(N);

    for (int i = 0; i < N; i++)
        numbers.push_back((double)i/N);
    
    auto transform =  [](double x){return x*x;};
    auto reduce = [](double a,double b){return a + b;};
    
    const int N_Thread = 8;
    std::vector<std::thread> workers;
    std::array<double,N_Thread> subResult{0};

    for(int i=0;i<N_Thread;i++)
    {   
        auto low  = numbers.begin()+i*numbers.size()/N_Thread;
        auto high = numbers.begin()+(i+1)*numbers.size()/N_Thread;

        workers.push_back(
            std::thread(
            transform_reduce<std::vector<double>::iterator,
            decltype(transform),
            decltype(reduce),double>,
            low,high,transform,reduce,std::ref(subResult[i])));
    }
    
    double result = 0;
    for(int i=0;i<N_Thread;i++)
    {
        workers[i].join();
        result = reduce(result,subResult[i]);
    }

    std::cout<<result<<std::endl;
}
