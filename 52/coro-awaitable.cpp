#include <coroutine>
#include <thread>
#include <iostream>
#include <future>
#include <cstdint>

#define CPPHTTPLIB_OPENSSL_SUPPORT
#include "httplib.h"

void print_hex(const std::string &s)
{
    for (const auto &c : s){
        std::cout << std::setw(2) << std::setfill('0') << std::hex << (int)(c & 0xff) << " ";
    }
    std::cout << std::endl;
}

struct promise_type;
struct MyCoroutine : std::future<std::string>, std::coroutine_handle<promise_type>
{
    using promise_type = ::promise_type;
};

struct awaitable
{
    bool await_ready()
    {
        std::cout << "        awaitable::await_ready() called\n";
        return false;
    }
    void await_suspend(std::coroutine_handle<> h)
    {
        std::cout << "        awaitable::await_suspend() called\n";
        std::thread th = std::thread([h, this]
                                        { 
                    try{ 
                        httplib::Client request{host};
                        //request.Get("/delay/3");
                        const auto response = request.Get(path);                                              
                        data = response->body;         
                    }
                    catch(...){
                        throw;
                    }
                std::cout<<"        awaitable::await_suspend: resume coroutine\n";
                h.resume(); });
        th.detach();
    }

    auto await_resume(){
        std::cout << "        awaitable::await_resume() called\n";
        return data;
    }
    std::string host{};
    std::string path{};
    std::string data{};
};

struct promise_type:std::promise<std::string>
{
    MyCoroutine get_return_object() { return {this->get_future(),std::coroutine_handle<promise_type>::from_promise(*this)}; }
    auto initial_suspend() { return std::suspend_always{}; }
    auto final_suspend() noexcept { return std::suspend_always{}; }
    void unhandled_exception() {}
    
    template<typename T>
    void return_value(T&& res){
        this->set_value(std::forward<T>(res));
    }

    auto await_transform(std::tuple<std::string, std::string> t){
        const std::string &host = std::get<0>(t);
        const std::string &path = std::get<1>(t);
        return awaitable{host, path};
    }
private:
    std::string _res{};
};


MyCoroutine coroFunc(const std::string host, const std::string path){
    std::cout << "    coroFunc: co_await http_get(host,path)\n";
    std::string res = co_await std::tuple(host, path); 
    co_return std::move(res); 
    std::cout << "    coroFunc: return\n";
}

int main(void){
    std::cout << "main: create coroutine\n";
    MyCoroutine coro1 = coroFunc("https://httpbin.io", "/bytes/64");
    MyCoroutine coro2 = coroFunc("https://httpbin.io", "/bytes/64");
    MyCoroutine coro3 = coroFunc("https://httpbin.io", "/bytes/64");
    std::cout << "main: resume coroutine\n";
    coro1.resume();
    coro2.resume();
    coro3.resume();

    std::cout << "get result from coroutine return object[1]:\n";
    print_hex(coro1.get());
    std::cout << "get result from coroutine return object[2]:\n";
    print_hex(coro2.get());
    std::cout << "get result from coroutine return object[3]:\n";
    print_hex(coro3.get());
}
