/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 18.结构与联合>> 配套例程
// struct.cpp
// 前后缀运算符重载示例
//
/////////////////////////////////////////////////////////////////

#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

enum class ColorType{
    Red=1,
    Blue=3,
    Yellow,
    Green=4
};

enum class ColorType2{
    Red,
    Blue,
    Yellow,
    Green
};

struct Date{
    unsigned short year,month,day;
};

struct StudentPlus{
    string name;
    string id;
    Date birthday;
    short gender;
    const string& getname() const{return name;};
};

union MyUnionType{
    unsigned long l;
    unsigned char c[8]; 
    struct{
        unsigned char i;
        unsigned char o;
        unsigned short v;
    }s; 
};

struct Student{
    char name[16];
    char id[8];
    Date birthday;
    short gender;
}student0;


struct StudentNew{
    char name[5];
    //string name;
    char id[7];
    Date birthday;
    short gender;
};

typedef struct _Student{
    char name[16];
    char id[8];
    time_t birthday;
    short gender;
}StudentOld;

int test_w(const char* fname)
{
    StudentNew student{"Tom","001",{2000,1,1},1};
    FILE* f = fopen(fname,"wb");
    fwrite(&student,sizeof(student),sizeof(char),f);
    fclose(f);
    return 0;
}

int test_r(const char* fname)
{
    StudentNew student={};
    FILE* f = fopen(fname,"rb");
    fread(&student,sizeof(student),sizeof(char),f);
    fclose(f);
    cout<<student.name<<","<<student.id<<",";
    cout<<student.birthday.year<<"-"<<student.birthday.month<<"-"<<student.birthday.day;
    return 0;
}

int main(void){
    StudentPlus student1{"Tom","001",0,1};
    Student student2{"Tom","001",0,1};
    StudentOld student3={"Tom","001",0,1};
    struct Student student4={"Tom","001",0,1};
    const unsigned char* p1 =(const unsigned char*)&student1;
    const unsigned char* p2 = (const unsigned char*)&student2;

    Student* pStudent=new Student({"Tom","001",0,1});
    //cout<<pStudent->name;
    //cout<<(*pStudent).gender;
    test_w("test.bin");
    test_r("test.bin");

    sizeof(MyUnionType);
    MyUnionType data1{},data2,data3;
    data1.l = 0x3EUL;
    data1.s={'f','s',12};
    ColorType color;
    color = ColorType::Blue;
    color = (ColorType)7;

    //* 以下未使用限定名导致编译错误*//
    /*
    cout<<"Red="<<Red<<endl;
    cout<<"Blue="<<Blue<<endl;
    cout<<"Yellow="<<Yellow<<endl;
    cout<<"Green="<<Green<<endl;
    */
}