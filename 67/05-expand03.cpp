#include <iostream>
template<typename ... Base>
class MyClass: public Base... {
public:
    MyClass() : Base()...{}
};


class BaseClass1 {
public:
    BaseClass1() {std::cout << "BaseClass1 constructor\n";}
};

class BaseClass2 {
public:
    BaseClass2() {std::cout << "BaseClass2 constructor\n";}
};

int main() {

    MyClass<BaseClass1, BaseClass2> mc;
}