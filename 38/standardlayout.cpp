#include <iostream>
#include <type_traits>

struct Base{
    int a;
    int b;
    
};

struct Derived1:public Base{
    int c;
};

struct Derived2:public Base{
    int func(){return a;}
};

int main(void)
{
    std::cout<<std::boolalpha;
    std::cout<<std::is_standard_layout<Derived1>::value<<"\n";
    std::cout<<std::is_standard_layout<Derived2>::value<<"\n";


}

   template< class T > struct std::is_copy_assignable;
   template< class T > struct is_trivially_copy_assignable;
   template< class T > struct is_nothrow_copy_assignable;