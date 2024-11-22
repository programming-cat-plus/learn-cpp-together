/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 30.智能指针:unique_ptr>> 配套例程
// sizeof.cpp
// 原生指针和unique_ptr的大小比较
//
/////////////////////////////////////////////////////////////////

#include <memory>
#include <iostream>
using namespace std;
class Rectangle{
public:
    Rectangle(double w,double h):width(w),height(h){}
    double area(){return width*height;}
    ~Rectangle(){std::cout<<"对象被释放"<<std::endl;}
private:
    double width;
    double height;
};

int main(void){
    
        unique_ptr<Rectangle> up1(new Rectangle(3.5,4.1));
        Rectangle* p2 = new Rectangle(3.5,4.1);
        std::cout<<"unique ptr size:"<<sizeof(up1)<<std::endl;
        std::cout<<"raw pointer size:"<<sizeof(p2)<<std::endl;
}