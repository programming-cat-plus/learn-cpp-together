#include <iostream>

template <typename DerivedClass>
class Base{
public:
    void interface() {
        static_cast<DerivedClass*>(this)->implementation();
    }
};

class Derived : public Base<Derived> {
public:
    void implementation() {
        std::cout << "Derived implementation called: " << private_member <<std::endl;
    }
private:
    int private_member = 42; 
};

int main() {
    Derived d;
    d.interface(); 

    Base<Derived> ub;
    ub.interface();
    return 0;
}