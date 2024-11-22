/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 30.智能指针:unique_ptr>> 配套例程
// unique.cpp
// unique_ptr示例
//
/////////////////////////////////////////////////////////////////

#include <memory>
#include <iostream>
#include <tuple>
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

template<typename T>
struct unique_ptr_deleter
{
	void operator()(T* resource) const
	{
		delete resource;
	}
};

int main(void){

    if(0)
    {
        unique_ptr<Rectangle> p1(new Rectangle(3.5,4.1));
        std::cout<<p1->area()<<std::endl;

        //unique_ptr<Rectangle> p2 = p1;
        //unique_ptr<Rectangle> p2(p1);

        unique_ptr<Rectangle> p2 = move(p1);
        std::cout<<p1->area()<<std::endl;
        std::cout<<p2->area()<<std::endl;

    }
    
    //unique_ptr<Rectangle> p2 = move(pDemo);
    //std::cout<<pDemo->area()<<std::endl;
    //std::cout<<p2->area()<<std::endl;

    {
        unique_ptr<Rectangle> p1(new Rectangle(3.5,4.1));
        p1 = nullptr;

        unique_ptr<Rectangle> p2(new Rectangle(3.5,4.1));
        p1 = move(p2);
    }

    {
        unique_ptr<Rectangle, unique_ptr_deleter<Rectangle>> p1(new Rectangle(3.5,4.1));
        p1->area();
        p1.reset(new Rectangle(5.5,4.1));
    }
}