#include <memory>
#include <iostream>
using namespace std;

struct S{
    char data[100];
};
int main(void)
{
    unique_ptr<S> up1=make_unique<S>();
    cout<<"移动前："<<endl;
    cout<<"up1:"<<up1.get()<<endl;
    unique_ptr<S> up2 = std::move(up1);

    cout<<"移动后："<<endl;
    cout<<"up1:"<<up1.get()<<endl;
    cout<<"up2:"<<up2.get()<<endl;
}