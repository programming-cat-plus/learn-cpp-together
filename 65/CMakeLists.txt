cmake_minimum_required(VERSION 3.31)
project(ExampleProject VERSION 1.0 LANGUAGES CXX)

add_executable(undefined_behavior avoid_undefined_behavior.cpp)
add_executable(simple simple_example.cpp)
add_executable(ttp ttp.cpp)
add_executable(enable_shared enable_shared_from_this.cpp)

set(BENCHMARK_ENABLE_TESTING NO) 

include(FetchContent)
FetchContent_Declare(
    googlebenchmark
    GIT_REPOSITORY https://github.com/google/benchmark.git
    GIT_TAG origin/main
)
FetchContent_MakeAvailable(googlebenchmark)
add_executable(crtp_Benchmark crtp_bench.cpp)
target_link_libraries(crtp_Benchmark PRIVATE benchmark::benchmark) 