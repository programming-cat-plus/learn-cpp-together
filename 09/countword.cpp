/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 9.编程练习>> 配套例程
// countword.cpp
// 统计单词数量
//
/////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

int main(void)
{
    const int maxSize = 255;
    char sentence[maxSize];

    cout<<"请输入英文句子："<<endl;

    cin.getline(sentence,maxSize);

    char c;
    int i = 0;
    bool flag = false;
    int count = 0;
    while(c=sentence[i])
    {
        if(c>='a'&&c<='z'||c>='A'&&c<='Z'||c=='-')
        {
            flag = true;
        }
        else
        {
            if(flag)
            {
                flag = false;
                count++;
            }
        }
        ++i;
    }
    if(flag)
        count++;
        
    cout<<"共有"<<count<<"个"<<endl;
    return 0;
}