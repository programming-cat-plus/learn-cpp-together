#include <iostream>
template<typename T>
class Printable{
public:
    void print() {
        std::cout<<"Printed from Printable."<<std::endl;
    }
};

template<typename T>
class ObjectCounter{
    public:
    ObjectCounter() { ++count; }
    ~ ObjectCounter() { --count; }
    static auto get() { return count; }
private:
    static unsigned int count;
};

template <typename T> 
unsigned int ObjectCounter<T>::count = 0;

template<template<typename> typename CRTP>
class MyClass : public CRTP<MyClass<CRTP>> {
};

template <template<typename...> typename... CRTPs>
class MyClass2 : public CRTPs<MyClass2<CRTPs...>>... {
};

int main(void){
    MyClass<Printable> obj1;
    obj1.print(); // This will call printImpl() of MyTemplateClass<int>
    MyClass<ObjectCounter> obj2;
    std::cout << "Object count of MyClass: " << obj2.get() << std::endl;

    MyClass2<Printable, ObjectCounter> obj3;
    obj3.print(); // This will call printImpl() of MyTemplateClass<int>
    obj3.get(); // This will call get() of ObjectCounter
    return 0;
}