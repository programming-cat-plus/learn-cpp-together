#include <thread>
#include <iostream>

void hello(const std::string& name)
{
    std::cout<<"Hello, "<<name<<".[Thread Id = "<<std::this_thread::get_id()<<"]\n";
}

int main(void)
{
    std::thread mythread(hello,std::string("World"));
    if(mythread.joinable())
        mythread.join();
    return 0;
}

