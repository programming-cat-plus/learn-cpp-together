#include <atomic>
#include <iostream>
#include <thread>

struct Channnel{
    void getData() {
        std::cout << "[Consumer] Wait for data ready \n";
        dataReady.wait(false); 
        std::cout << "[Consumer] Data is: " << data << '\n';
        dataReady.clear(); 
    }

    void setData(const std::string& v) {
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        std::cout << "[Producer] Write data \n";
        data = v;
        dataReady.test_and_set(); 
        dataReady.notify_one();
    }
private:
    std::string data;
    std::atomic_flag dataReady = ATOMIC_FLAG_INIT;
};

int main() {
    Channnel channel;
    std::thread consumer(Channnel::getData,&channel); 
    std::thread producer(Channnel::setData,&channel,"Hello, world");

    consumer.join();
    producer.join();
}


