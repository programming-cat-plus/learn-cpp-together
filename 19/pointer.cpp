/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 19.运算符重载>> 配套例程
// pointer.cpp
// 间接引用运算符重载示例
//
/////////////////////////////////////////////////////////////////

struct Complex{
    float r,i;
};

class LocalComplexPtr{
private:
    Complex* m_pComp;
public:
    LocalComplexPtr(Complex* p):m_pComp(p){}

    Complex* operator->(){return m_pComp;}
    ~LocalComplexPtr(){
        if(m_pComp)delete m_pComp;}
    LocalComplexPtr(const LocalComplexPtr&)=delete;
    LocalComplexPtr& operator=(const LocalComplexPtr&)=delete;
};

int main(void){
    LocalComplexPtr pComplex1(new Complex({0.1,0.5}));
    pComplex1->i++;
    LocalComplexPtr pComplex2(0);
}
