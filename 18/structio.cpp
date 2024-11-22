/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 18.结构与联合>> 配套例程
// structbit.cpp
// struct序列化，POD - Plain Old Data数据结构存取示例
//
/////////////////////////////////////////////////////////////////

#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

struct Date{
    unsigned short year,month,day;
};

struct Student{
    char name[5];
    char id[7];
    Date birthday;
    short gender;
};

int test_w(const char* fname)
{
    Student student{"Tom","008",{2001,2,3},1};
    FILE* f = fopen(fname,"wb");
    fwrite(&student,sizeof(student),sizeof(char),f);
    fclose(f);
    return 0;
}

int test_r(const char* fname)
{
    Student student={};
    FILE* f = fopen(fname,"rb");
    fread(&student,sizeof(student),sizeof(char),f);
    fclose(f);
    cout<<student.name<<","<<student.id<<",";
    cout<<student.birthday.year<<"-"<<student.birthday.month<<"-"<<student.birthday.day;
    return 0;
}

int main(void){
    Student* pStudent=new Student({"Tom","001",0,1});
    test_w("test.bin");
    test_r("test.bin");
}