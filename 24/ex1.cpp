/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 24.异常>> 配套例程
// ex1.cpp
// 异常的抛出和捕捉示例
//
/////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;
#include <stdexcept>

float divide(float a, float b)
{
    if(b==0)
        throw runtime_error(" Divided by zero! ");

    return a/b;
}

class my_exception:public exception{
private:
    unsigned int error_code;
    string reason;
public:
    my_exception(const string& message,int code):reason(message),error_code(code){};
    virtual const char* what() const noexcept override
    {
        return reason.c_str();
    };
};

int main(void)
{
    int a=10.1;
    int b = 0;

    try
    {
        int c =divide(a,b);
        cout<<"c=."<<c<<endl;
    }
    catch(runtime_error& e)
    {
        cout<<"exception:"<<e.what()<<endl;
    }
    catch(my_exception& e)
    {
        cout<<"exception:"<<e.what()<<endl;
    }
    catch(exception& e)
    {
        cout<<"exception:"<<e.what()<<endl;
    }
    catch(...)
    {
        cout<<"unkown exception."<<endl;
        throw;
    }

    try{
        throw my_exception("自定义异常",1000);
    }
    catch(my_exception& e){
        cout<<e.what()<<endl;
    }

    return 0;
}