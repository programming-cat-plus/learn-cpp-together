/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 31.智能指针:shared_ptr和weak_ptr>> 配套例程
// waekptr2.cpp
// weak_ptr示例
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

#define NO_EXCEPTION 0
#if NO_EXCEPTION==1
int main(void){
    weak_ptr<Rectangle> w_p1;
    {
        shared_ptr<Rectangle> s_p1(new Rectangle(3.5,4.1));
        shared_ptr<Rectangle> s_p2 = s_p1;

        w_p1 = s_p2;
        cout<<"作用域内usecount="<<w_p1.use_count()<<endl;
    }
    cout<<"作用域外usecount="<<w_p1.use_count()<<endl;
    cout<<"expired="<<w_p1.expired()<<endl;
}
#else
int main(void){
    try{
        weak_ptr<Rectangle> w_p1;
        {
            shared_ptr<Rectangle> s_p1(new Rectangle(3.5,4.1));
            shared_ptr<Rectangle> s_p2 = s_p1;

            w_p1 = s_p2;
            shared_ptr<Rectangle> s_p3(w_p1);
            cout<<"作用域内s_p3="<<s_p3<<endl;
        }
        shared_ptr<Rectangle> s_p3(w_p1);
        cout<<"作用域外sp3="<<s_p3<<endl;
    }
    catch(bad_weak_ptr)
    {
        cout<<"对象失效"<<endl;
    }
}
#endif