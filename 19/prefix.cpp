/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 19.运算符重载>> 配套例程
// pointer.cpp
// 前后缀运算符重载示例
//
/////////////////////////////////////////////////////////////////

class ExampleClass
{
private:
    int m_a;
    // prefix increment
    ExampleClass& operator++()
    {
        m_a++;
        return *this; 
    }
 
    // postfix increment
    ExampleClass operator++(int)
    {
        ExampleClass temp = *this; 
        operator++();  
        return temp;   
    }

    int operator()(int a){
        return 0;
    };
};

ExampleClass& operator--(ExampleClass& obj,int){
    ExampleClass obj
    return temp;
}

ExampleClass& operator--(ExampleClass& obj){

}

