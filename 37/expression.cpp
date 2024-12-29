#include <iostream>
int main(void)
{
    {
        int a;
        decltype((a)) b = a;
        int *p = &(a);
        int *p1 = &a;
        std::cout<<"p="<<p<<", p1="<<p1<<std::endl;
        {
            decltype(auto) a = 1+2*3;
            decltype(1+3*1.1) b;
        }

        {
            std::string s1 = "Hello";
            decltype(s1+",world") s2 = s1;
            decltype(s1.append(",world")) s3 = s1;
            std::cout<<s3<<std::endl;
        }

        {
            std::string s1 = "Hello";
            decltype(auto) s2 = s1+",world";
            decltype(auto) s3 = s1.append(",world");
            std::cout<<s3<<std::endl;
        }
    }
}