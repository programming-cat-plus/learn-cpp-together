/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 31.智能指针:shared_ptr和weak_ptr>> 配套例程
// shared.cpp
// shared_ptr示例
//
/////////////////////////////////////////////////////////////////

#include <memory>
#include <iostream>

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
    using std::shared_ptr;

    {
        shared_ptr<Rectangle> p1(new Rectangle(3.5,4.1));
        std::cout<<p1->area()<<std::endl;

        shared_ptr<Rectangle> p2 = p1;
        shared_ptr<Rectangle> p3(p2);

        std::cout<<p1->area()<<std::endl;
        std::cout<<p3.use_count()<<std::endl;
        int n =sizeof(p3);
        p3.get();
    }
}

