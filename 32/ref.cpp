/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 32.lambda表达式>> 配套例程
// ref.cpp
// lamda捕获引用示例
//
/////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

int main(void)
{
    int x = 7;
    float y = 3.0;
    auto p = [&x, &y](int a, int b) -> float
    {
        return x * y + a * b;
    };

    cout << p(10, 20) << endl;
    y += 1.5;
    cout << p(10, 20) << endl;
}
