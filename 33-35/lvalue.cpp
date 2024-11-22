#include <iostream>
int &refNumber()
{
    static int n = 1;
    return n;
}

int main(void)
{
    {
        const int a = 5;
        const int &b = a;
        int c;
        int *ptr = &c;
    }

    {
        int b = 4;
        int &c = b;
    }

#if 0
    {
        int *p = &4; //错误示例
    }
#endif

    {
        int a = 8;
        double m = 1.5;

        int *p = new int{5};
        *p = 4;

        int b[5];
        b[1] = 10;

        int &r = a;
    }

    {
        struct S
        {
            int id;
        } s1;
        s1.id = 3;
    }
    {
        refNumber()=5;
        std::cout<<refNumber()<<std::endl;
    }
}

