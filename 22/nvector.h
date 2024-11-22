/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 22.类模板>> 配套例程
// nvector.h
// 整形常量模板参数示例
//
/////////////////////////////////////////////////////////////////

#include <initializer_list>

template<typename T=float, int N=5>
class Vector{
private:
    T m_values[N];
public:
    Vector(T values[N]){
        for(int i=0;i<N;i++){
            m_values[i] = values[i];
        }
    }

    Vector(std::initializer_list<T> __l){
        int i=0;
        for(auto v:__l)
            m_values[i++] = v;
    }

    T getMax(){
        T maxvalue = m_values[0];
        for(T v:m_values)
            maxvalue = maxvalue>v?maxvalue:v;
        return maxvalue;
    }
};