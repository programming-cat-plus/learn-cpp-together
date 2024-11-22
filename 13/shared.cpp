/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 13.指针和引用>> 配套例程
// shared.cpp
// 智能指针
//
/////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class Shape{
        string shapeName;
    public:
        int positionX, positionY;  
        
        const string& getName(){
            return shapeName;
        }

        void setName(const string& shapeName){
            this->shapeName = shapeName;
        }     

        Shape(int x,int y);
    private:
        Shape();
};

Shape::Shape(int x, int y){
            positionX = x;
            positionY = y;
};

Shape::Shape(){
    positionX=0; 
    positionY=0;
}

int main(void)
{
   shared_ptr<Shape> pShape = shared_ptr<Shape>(new Shape(0,0));
   pShape->setName("形状一");
   cout<<pShape->getName()<<endl;
   return 0;
}