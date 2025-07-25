#include <chrono>
#include <iostream>
#include <thread>

using namespace std::chrono_literals;
int main() {

    std::thread ([]() {
        std::this_thread::sleep_for(1s);
        std::cout << "Thread finished after 1 second." << std::endl;
    }).join();

    std::cout << "Main thread continues after the spawned thread." << std::endl;
    return 0;
}


