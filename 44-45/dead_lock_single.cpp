#include <mutex>

class DoSomthing{
public:
    int func1(){
        std::lock_guard lock(mtx);
        count*=2;
        func2();
        return count;
    }
    void func2(){
        std::lock_guard lock(mtx);
        count++;
    }
private:
    std::mutex mtx;
    int count = 0;
};

int main(void)
{
    DoSomthing op;
    int result =op.func1(); 
}

