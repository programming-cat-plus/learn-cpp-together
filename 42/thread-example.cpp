#include <thread>
#include <iostream>
void myfunc(double param1,double param2, double& result)
{
    result = param1+param2;
}

struct myfunctor{
    void operator()(double param1,double param2){
        result = param1+param2;
    };
    double result=0;
};

class MyClass{
public:
    void sum(double param1,double param2){
        result = param1+param2;
    }
    double result=0;
} ;

int main(void)
{
    double a = 1.1;
    double b = 3.2;
    double result = 0;

    std::thread thread1(myfunc,a,b,std::ref(result));

    myfunctor f;
    std::thread thread2(f,a,b);

    MyClass obj;
    std::thread thread3(MyClass::sum,&obj,a,b);

    double result2;
    std::thread thread4([&result2](double a,double b){result2=a+b;},a,b);

    thread1.join();
    thread2.join();
    thread3.join();
    thread4.join();

    std::cout<<"result="<<result<<"\n";
    std::cout<<"f.result="<<f.result<<"\n";
    std::cout<<"obj.result="<<obj.result<<"\n";
    std::cout<<"result2="<<result2<<"\n";
}

