#include <mutex>
#include <iostream>
#include <memory>
#include <future>
#include <thread>
#include <chrono>

class MyResource : public std::enable_shared_from_this<MyResource>
{
public:
    MyResource() : value(0) {}
    auto process()
    {
        auto future = std::async(std::launch::async, [self = shared_from_this()]()
                                 {     
            std::lock_guard lock(self->mtx);       
            std::this_thread::sleep_for(std::chrono::seconds(3)); // Simulate some processing delay             
            self->value++;
            return self->value; });

        return future;
    }

    void setValue(int v)
    {
        std::lock_guard lock(mtx);
        value = v;
    }

    int getValue()
    {
        std::lock_guard lock(mtx);
        return value;
    }

private:
    int value;
    std::mutex mtx;
};

int main()
{
    std::future<int> fut;

    {
        std::shared_ptr<MyResource> pt = std::make_shared<MyResource>();
        
        pt->setValue(33);
        std::cout << "Data from resource: " << pt->getValue() << std::endl;
        std::cout<< "Use count [before process()]: " << pt.use_count() << std::endl;
        fut = pt->process();   
        std::cout<< "Use count [after process()]: " << pt.use_count() << std::endl;     
    }

    std::cout << "Process result is: " << fut.get(); // Wait for the async task to complete
    return 0;
}