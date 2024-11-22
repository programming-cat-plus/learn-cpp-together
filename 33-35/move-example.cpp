#include <cstring>
#include <iostream>
#include <vector>
#include "CharBuffer.h"
using namespace std;

CharBuffer generate_nv(int n)
{
    CharBuffer buf(n);
    cout << &buf << endl;
    return buf;
}

CharBuffer generate(int n)
{
    return CharBuffer(n);
}

int main()
{
    {
        cout << "=========Copy Expamle=========" << endl;
        CharBuffer buff1(100);
        CharBuffer buff2 = buff1;
    }

    {
        cout << "=========Copy Elision Expamle=========" << endl;
        CharBuffer buff2{CharBuffer(100)};
    }

    {
        cout << "=========RVO Expamle=========" << endl;
        CharBuffer buff2 = generate(100);
    }

    {
        cout << "=========NRVO example=========" << endl;
        CharBuffer buff2 = generate_nv(100);
        cout << &buff2 << endl;
    }

    {
        cout << "=========Move example=========" << endl;
        CharBuffer buff1(100);
        CharBuffer buff = std::move(buff1);
    }
    {
        cout << "=========Move example=========" << endl;
        CharBuffer buff2;
        {
            CharBuffer buff1(100);
            buff2 = std::move(buff1);
        }
    }

    {
        cout << "=========Static cast example=========" << endl;
        CharBuffer buff1(100);
        CharBuffer buff = static_cast<CharBuffer &&>(buff1);
    }

    {
        cout << "=========std::vector example===========" << endl;
        vector<CharBuffer> buffs;
        buffs.reserve(5);
        cout << "=======push_back=============\n";
        CharBuffer a(100);
        buffs.push_back(a);
        cout << "=======end push_back=============\n";
        cout << "=======emplace_back=============\n";
        buffs.emplace_back(100);
        cout << "=======end emplace_back=============\n";
        cout << "=======intsert===============\n";
        buffs.insert(buffs.begin(), CharBuffer(100));
        cout << "=======end intsert===============\n";
    }
}
