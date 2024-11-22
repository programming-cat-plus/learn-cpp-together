/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 9.编程练习>> 配套例程
// countletters.cpp
// 统计字母数量
//
/////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

int main(void)
{
    const int maxSize = 255;
    char sentence[maxSize]={};

    cout<<"请输入英文句子："<<endl;

    cin.getline(sentence,maxSize);

    int count[26]={0};
    char c;
    int idx = 0;
    for(int i=0;c=sentence[i];i++)
    {
        if(c>='a'&&c<='z')
        {
            idx = c-'a';
        }
        else if(c>='A'&&c<='Z')
        {
            idx = c-'A';
        }
        else
            continue;

        
        count[idx]++;
    }

    for(int i=0;i<26;i++)
    {
        if(count[i])
         cout<<char('a'+i)<<":"<<count[i]<<endl;
    }
    return 0;
}