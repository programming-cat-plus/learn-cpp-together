/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 20.宏定义>> 视频课程 配套例程
// line.cpp
// 打印源文件名、行号
//
/////////////////////////////////////////////////////////////////
#include <iostream>
using namespace std;

int main()
{
    cout << "源文件: " << __FILE__ << endl;
    cout << "行号：" << __LINE__ << endl;
    cout << "编译开始于" << __DATE__ << "," << __TIME__ << endl;
    cout << "编译器的__cplusplus值是: " << __cplusplus << endl;
    return 0;
}
