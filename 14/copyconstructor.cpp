/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 14.类和对象>> 配套例程
// inheritance.cpp
// 拷贝构造函数
//
/////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

class Shape{
    int positionX;
    int positionY;
public:
    Shape(int x,int y):positionX(x),positionY(y){};
    Shape(const Shape& other)
    {
        cout<<"Copy constructor called!"<<endl;
    }
};

int main(void)
{
    Shape shape1(0,0);

    Shape shape2 = shape1;
    Shape shape3(shape1);
    Shape shape4 = Shape(shape1);
    Shape* pShape = new Shape(shape1);

    return 0;
}