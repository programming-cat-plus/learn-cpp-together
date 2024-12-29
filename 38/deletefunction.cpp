#include <iostream>

bool isEven( int number)
{
    return (number^1)&1;
}

bool isEven(double)=delete;

using namespace std;
int main(){
    //bool r = isEven(2.31);
    //cout<<boolalpha<<r<<endl;
    for(int i=1;i<5;i++)
        std::cout<<i<<isEven(i)<<std::endl;
}