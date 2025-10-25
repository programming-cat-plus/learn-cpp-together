template<typename ... Args>
class MyClass {};

template<typename ... Base>
class MyClass2: public Base... {
    MyClass2() : Base()...{}
};

template<typename ... Args>
void f(Args... args) {
}

template<int... Is>
void g() {
}

int main() {
    MyClass<> mc1;
    MyClass<int, double, char> mc2;
}