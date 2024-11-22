/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 17.类域对象（3）>> 配套例程
// friend.cpp
// 友元示例
//
/////////////////////////////////////////////////////////////////
class B;

class A{
public:
    A():m_value(0){};
private:
    int m_value;
friend class B;
friend int inc(A&);
};

class B{
public:
    int inc(A& obj)
    {
        obj.m_value++;
        return obj.m_value;
    }
};

int inc(A& obj)
{
    obj.m_value++;
    return obj.m_value;
}

main(){
    B obj1;
    A obj2;
    obj1.inc(obj2);
}

