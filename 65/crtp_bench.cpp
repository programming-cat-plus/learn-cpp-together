#include <iostream>
#include <cmath>
#include <benchmark/benchmark.h>

namespace crtp
{
    template <typename Derived>
    class Shape
    {
    public:
        void area()
        {
            static_cast<Derived *>(this)->calc_area();
        }
    };

    class Triangle : public Shape<Triangle>
    {
    public:
        Triangle(float a, float b, float c) : a(a), b(b), c(c)
        {
            if (a <= 0 || b <= 0 || c <= 0)
            {
                throw std::invalid_argument("Sides must be positive");
            }
            if (a + b <= c || a + c <= b || b + c <= a)
            {
                throw std::invalid_argument("Invalid triangle sides");
            }
        }

        float calc_area()
        {
            float s = (a + b + c) / 2;
            // Calculate area using Heron's formula
            return std::sqrt(s * (s - a) * (s - b) * (s - c));
        }

    private:
        float a, b, c; // Example sides of the triangle
    };
}

namespace polymorphic
{
    class Shape
    {
    public:
        virtual float area() = 0; // Pure virtual function
    };

    class Triangle : public Shape
    {
    public:
        Triangle(float a, float b, float c) : a(a), b(b), c(c)
        {
            if (a <= 0 || b <= 0 || c <= 0)
            {
                throw std::invalid_argument("Sides must be positive");
            }
            if (a + b <= c || a + c <= b || b + c <= a)
            {
                throw std::invalid_argument("Invalid triangle sides");
            }
        }

        float area() override
        {
            float s = (a + b + c) / 2;
            // Calculate area using Heron's formula
            return std::sqrt(s * (s - a) * (s - b) * (s - c));
        }

    private:
        float a, b, c; // Example sides of the triangle
    };
}

static void Crtp(benchmark::State& state) {
  // Code inside this loop is measured repeatedly
  
  for (auto _ : state) {
    crtp::Triangle t(3.0f, 4.0f, 5.0f);
    t.area();
    // Make sure the variable is not optimized away by compiler
    benchmark::DoNotOptimize(t);
  }
}
// Register the function as a benchmark
BENCHMARK(Crtp);

static void Polymorphic(benchmark::State& state) {
  // Code before the loop is not measured
  for (auto _ : state) {
    polymorphic::Triangle t(3.0f, 4.0f, 5.0f);
    t.area();
    // Make sure the variable is not optimized away by compiler
    benchmark::DoNotOptimize(t);
  }
}
BENCHMARK(Polymorphic);

BENCHMARK_MAIN();
