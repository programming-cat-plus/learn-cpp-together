#include <coroutine>
#include <thread>
#include <iostream>
struct promise;
struct MyCoroutine : std::coroutine_handle<promise>
{
    using promise_type = ::promise;
};

struct promise
{
    MyCoroutine get_return_object() { return {MyCoroutine::from_promise(*this)}; }
    auto initial_suspend() { return std::suspend_always{}; }
    auto final_suspend() noexcept { return std::suspend_always{}; }
    void unhandled_exception() {}
};

struct awaitable
{
    bool await_ready(){
        std::cout << "        awaitable::await_ready() called\n";
        return false;
    }
    void await_suspend(std::coroutine_handle<> h){
        std::cout << "        awaitable::await_suspend() called\n";
        h.resume();
    }

    auto await_resume(){
        std::cout << "        awaitable::await_resume() called\n";
        return 666;
    }
};

MyCoroutine coroFunc(void){
    std::cout << "    coroFunc: co_await awaitable\n";
    co_await awaitable{};
    std::cout << "    coroFunc: return\n";
}

int main(void){
    std::cout << "main: create coroutine\n";
    MyCoroutine coro = coroFunc();
    std::cout << "main: resume coroutine\n";
    coro.resume();
    std::cout << "main: finished\n";
}




