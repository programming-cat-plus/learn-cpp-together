/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 22.类模板>> 配套例程
// vector3.h
// 类模板示例
//
/////////////////////////////////////////////////////////////////


//Vector3类主模板

template<typename T> 
class Vector3
{
    private:
        T m_vec[3];
    public:
        Vector3(T v1, T v2, T v3){
            m_vec[0] = v1;
            m_vec[1] = v2;
            m_vec[2] = v3;
        };
        T getMax();
};


template<typename T> 
T Vector3<T>::getMax(){
    T temp = m_vec[0]>m_vec[1]?m_vec[0]:m_vec[1];
    return temp>m_vec[2]?temp:m_vec[2];
}

// Vector3<char>特化实例
template<> 
class Vector3<char>
{
    private:
        char m_vec[4];
    public:
        Vector3(char v1, char v2, char v3){
            m_vec[0] = v1;
            m_vec[1] = v2;
            m_vec[2] = v3;
            m_vec[3] = 0;
        };

        const char* asString() const{
            return m_vec;
        };

};

