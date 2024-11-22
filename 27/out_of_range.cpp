/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 27.STL容器(1)>>视频配套例程
// out_of_range.cpp
// std::vector 越界抛出异常示例
//
/////////////////////////////////////////////////////////////////

#include <vector>
#include <iostream>
using namespace std;

int main(void)
{
    vector<int> numbers;
    try
    { 
        cout << "大小\t容量" << endl;
        for (int i = 0; i < 10; i++)
        {
            numbers.push_back(i);
            cout << numbers.size() << "\t" << numbers.capacity() << endl;
        }
        numbers.at(10) = 200;
    }
    catch (out_of_range &e)
    {
        cout << e.what() << endl;
    }

    for (int i = 0; i < 11; i++)
        cout << numbers[i] << ",";

    cout << "\n"
         << numbers.size() << endl;
    // cout<<numbers.size()<<endl;
    // cout<<numbers.capacity()<<endl;
}