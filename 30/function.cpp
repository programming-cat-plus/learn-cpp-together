/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 30.智能指针:unique_ptr>> 配套例程
// container_banchmark.cpp
// unique_ptr所有权转移示例
//
/////////////////////////////////////////////////////////////////
#include <iostream>
#include <memory>
using namespace std;

class Bread{
public:
    Bread(){cout<<"面包做好了"<<endl;}
    ~Bread(){cout<<"面包没了"<<endl;}
};

unique_ptr<Bread> makebread(){
    return unique_ptr<Bread>(new Bread());
}

void eat(unique_ptr<Bread> bread){
    cout<<"面包被吃了"<<endl;
}

int main(void){
    cout<<"开始"<<endl;
    auto upBread = makebread();
    //eat(upBread);
    eat(move(upBread));
    cout<<"结束"<<endl;
}

