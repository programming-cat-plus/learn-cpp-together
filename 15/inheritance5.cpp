/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 15.类和对象（2）>> 配套例程
// inheritance5.cpp
// 继承示例
//
/////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
using namespace std;

class Shape{
public:
    virtual void draw()=0;
};

class Polygon:public Shape{
public:
    virtual void draw(){
        cout<<"画图功能：多边形"<<endl;
    }
};

class Rectangle:public Polygon
{
public:
    void draw()
    {
        cout<<"画图功能：长方形"<<endl;
    }
};

class Triangle:public Polygon
{
public:
    void draw()
    {
        cout<<"画图功能：三角形"<<endl;
    }
};

int main(void){
    Shape* p1 = new Polygon();
    Shape* p2 = new Triangle();
    Shape* p3 = new Rectangle();

    vector<Shape*> list{p1,p2,p3}; 

    for(auto p: list)
    {
        p->draw();
    }
}
