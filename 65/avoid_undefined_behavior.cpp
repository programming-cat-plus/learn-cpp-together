#include <iostream>

//#define UB // Uncomment this line to introduce undefined behavior (UB)
template <typename Derived>
class Base{
public:
    void interface() {
        static_cast<Derived*>(this)->implementation();
    }
#ifndef UB
private:
    Base() = default; // Protected constructor to prevent direct instantiation and ub
    friend Derived; // Allow Derived to access Base's private members
#endif
};

class Derived : public Base<Derived> {
public:
    void implementation() {
        std::cout << "[1]Derived implementation called: " << private_member <<std::endl;
    }
private:
    int private_member = 42; // Example of a private member
};

class Derived2 : public Base<Derived> {
public:
    void implementation() {
        std::cout << "[2]Derived implementation called: " << private_member <<std::endl;
    }
private:
    float private_member = 1.0; // Example of a private member
};

int main() {
    Derived d;
    d.interface(); 

    Base<Derived> ub;
    ub.interface();

    Derived2 d2;
    d2.interface();
    return 0;
}
