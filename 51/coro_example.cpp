#include <iostream>
#include <coroutine>

struct MyCoroutine{
    struct promise_type{
        MyCoroutine get_return_object(){
            return MyCoroutine(std::coroutine_handle<promise_type>::from_promise(*this));
        }
        std::suspend_always initial_suspend() { return {}; }
        std::suspend_always final_suspend() noexcept { return {}; }
        //std::suspend_always yield_value(int v) {_value = v;return {};}
        void return_value(int v) { _value = v; }
        auto yield_value(int v) { _value = v; return std::suspend_always{};}
        void unhandled_exception() {}
    public:
        int get(){return _value;}
    private:
        int _value;
    };
    MyCoroutine(std::coroutine_handle<promise_type> coroutine): handle(coroutine) {} 
    int get() { handle.resume(); return handle.promise().get();}
    operator bool(){return !handle.done();};
private:
    std::coroutine_handle<promise_type> handle;
};

MyCoroutine coroFunc()
{
    std::cout << "Hello, world!" << std::endl;
    co_yield 888;
    co_yield 999;
    co_return 666;
}

int main()
{
    MyCoroutine coro = coroFunc();
    while(coro)
    {
        int value = coro.get();
        std::cout<<"value="<<value<<std::endl;
    }
}

