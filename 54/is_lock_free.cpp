#include <typeinfo>
#include <iostream>
#include <memory>
#include <atomic>
#include <utility>

#define islockfree(T) \
    std::cout<< std::boolalpha << "atomic<"<< #T <<">\t"<<std::atomic<T>{}.is_lock_free()<<std::endl;

struct A { int  a[100]; };
struct B { char b[8]; };

int main(void)
{
    std::cout<<"类型\t\t是否无锁\n";
    islockfree(int);
    islockfree(double);
    islockfree(char);
    islockfree(bool);
    islockfree(char*);
    islockfree(A);
    islockfree(B);
    islockfree(std::shared_ptr<std::string>);
    islockfree(std::shared_ptr<int>);
    return 0;
}
