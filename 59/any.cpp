#include <any>
#include <iostream>
#include <vector>
#include <map>
std::ostream& operator<<(std::ostream& o, std::vector<int> v)
{
    o << "[";
    for(auto i:v)
    {
        o << i << ",";
    }
    o << "]";
    return o;
}

void f1()
{
    std::any a{1};    
    std::cout << std::any_cast<int>(a) << std::endl;

    a = std::vector<int>{1,2,3};
    std::cout << std::any_cast<std::vector<int>>(a) << std::endl;

    a.emplace<std::string>("world");
    std::cout << std::any_cast<std::string>(a) << std::endl;

    std::any b = std::string("hello");

    a = b;
    try{
        std::cout << std::any_cast<int>(a) << std::endl;
    } catch (const std::bad_any_cast& e) {
        std::cout << "Bad any cast: " << e.what() << std::endl;
    }

    auto v = std::any_cast<int*>(&a);
    if(v != nullptr)
    {
        std::cout << *v << std::endl;
    }
    else
    {
        std::cout << "nullptr" << std::endl;
    }
}

void f2(){
    std::map<std::string,std::any>  properties;
    properties["title"] = std::string("Hello World");
    properties["count"] = 10;
    properties["price"] = 19.99;
    properties["tags"] = std::vector<int>{2,13,1};
    properties["unknown"] = std::vector<std::string>{"2","13","1"};
    
    for(auto p:properties)
    {
        auto key = p.first;
        auto v = p.second;
        std::cout << key <<":";

        if(p.second.type() == typeid(int)){
            std::cout<<std::any_cast<int>(v)<<std::endl;
        }
        else if(v.type() == typeid(double)){    
            std::cout<<std::any_cast<double>(v)<<std::endl;
        }
        else if(v.type() == typeid(const char*)){
            std::cout<<std::any_cast<const char*>(v)<<std::endl;
        }
        else if(v.type() == typeid(std::string)){
            std::cout<<std::any_cast<std::string>(v)<<std::endl;
        }
        else if(v.type() == typeid(std::vector<int>)){
            std::cout<<std::any_cast<std::vector<int>>(v) <<std::endl;
        }
        else{
            std::cout<<"无法处理的类型:"<<v.type().name()<<std::endl;
        }
    }
}


int main(void)
{
    f1();
    f2();
    return 0;
}