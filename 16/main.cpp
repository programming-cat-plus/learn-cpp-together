/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 16.编程练习（3）>> 配套例程
// main.cpp
// 计算图形表面积示例
//
/////////////////////////////////////////////////////////////////

#include "ui.h"
#include <vector>
int main(void)
{
    vector<Generator*> generator{new RectangleGenerator(),new CircleGenerator()};

    while(true)
    {
        cout<<"请选择要计算的图形："<<endl;
        int i;
        for(i=0;i<generator.size();i++)
        {
            cout<<i<<": "<<generator[i]->getDisplayName()<<", ";            
        }
        cout<<i<<": 退出"<<endl;

        int idx = 0;
        cin>>idx;

        if(idx==generator.size())
            break;

        if(idx<0||idx>generator.size())
        {
            cout<<"没有这个选项！";
            continue;
        }

        Shape* pShape = generator[idx]->generateShapeFromInput();
        cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
        cout<<"\t面积="<<pShape->area()<<",";
        cout<<"周长="<<pShape->perimeter()<<endl;
        cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n"<<endl;

    }
}