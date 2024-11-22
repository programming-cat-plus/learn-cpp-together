
#pragma once

#define PI 3.1415926

class Shape{
public:
    virtual float perimeter()=0;
    virtual float area()=0;
};

class Rectangle:public Shape
{
private:
    float m_width;
    float m_height;
public:
    Rectangle(float width,float height){
        m_width = width;
        m_height = height;

    }
    virtual float perimeter(){
        return 2*(m_width+m_height);
    }

    virtual float area(){
        return m_height* m_width;
    }
};

class Circle:public Shape{
private:
    float m_radius;
public:
    Circle(float radius){
        this->m_radius = radius;
    }

    virtual float perimeter(){
        return 2*PI*m_radius;
    }

    virtual float area(){
        return PI*m_radius*m_radius;
    }
};

