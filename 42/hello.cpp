#include <thread>
#include <iostream>
#include <array>

void greeting(int idx){
    printf("Hello from thread %d\n",idx); //printf id thread-safe
    //std::cout<<"Hello from thread "<<idx<<std::endl; //cout is not thread-safe
}

int main(void)
{
    const int N = 10;
    std::array<std::thread,N> workers;
    for(int i=0;i<N;i++)
    {
        workers[i] = std::thread(greeting,i);
    }

    for(auto& worker:workers)
    {
        worker.join();
    }
};
