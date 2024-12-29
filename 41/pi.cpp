#include <iostream>
#include <array>
#include "autotimer.h"

// 顺序计算pi
double compute_pi_seq(const long num_steps)
{
    double step = 1.0 / num_steps;
    double sum = 0.0;
    for (long i = 0; i < num_steps; i++)
    {
        double x = (i + 0.5) * step;
        sum += 4.0 / (1.0 + x * x);
    }
    return sum * step;
}


// 并行计算pi.
double compute_pi_parallel(const long num_steps)
{
    double step = 1.0 / num_steps;
    double sum = 0.0;
    // parallelize loop and reduce
#pragma omp parallel for reduction(+ : sum)
    for (long i = 0; i < num_steps; i++)
    {
        double x = (i + 0.5) * step;
        sum += 4.0 / (1.0 + x * x);
    }
    return sum * step;
}

int main(void)
{
    const int N = 1000000000L;
    double pi = 0;

    {
        AutoTimer autoTimer("顺序计算Pi ");
        pi = compute_pi_seq(N);
    }

    std::cout << pi << std::endl;

    {
        AutoTimer autoTimer("openmp并行计算Pi");
        pi = compute_pi_parallel(N);
    }

    std::cout << pi << std::endl;
}

