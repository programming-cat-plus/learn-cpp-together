#include <memory>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <chrono>
#include <iostream>


class AutoTimer{
    using high_resolution_clock=std::chrono::high_resolution_clock;
private:
    high_resolution_clock::time_point startTime;
    std::string description;
public:
    AutoTimer(const char* desc):description(desc){ startTime = high_resolution_clock::now();};
    ~AutoTimer(){
        high_resolution_clock::time_point endTime = high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count();
        std::cout<<description<<":"<<duration<<" us"<<std::endl;
    }
};