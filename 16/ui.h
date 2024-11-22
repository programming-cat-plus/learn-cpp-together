#include "shape.h"
#include <iostream>

using namespace std;

class Generator{
protected:
    string m_displayName;
public:
    virtual Shape* generateShapeFromInput()=0;
    const string& getDisplayName(){return m_displayName;}
};

class RectangleGenerator:public Generator{
public:
    RectangleGenerator(){
        m_displayName = "长方形";
    };
    virtual Shape* generateShapeFromInput(){
        float width,height;
        cout<<"请输入长方形的宽:";
        cin>>width;
        cout<<"请输入长方形的高:";
        cin>>height;
        return new Rectangle(width,height);
    };
};

class CircleGenerator:public Generator{
public:
    CircleGenerator(){
        m_displayName = "圆";
    };
    virtual Shape* generateShapeFromInput(){
        float radius;
        cout<<"请输入半径"<<endl;
        cin>>radius;
        return new Circle(radius);
    };
};


