/////////////////////////////////////////////////////////////////
// 
// <<一起来学C++ 25.类型转换>>视频 配套例程
// dynacast.cpp
// dynamic_cast示例
//
/////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

class CBase{
public:
    virtual ~CBase(){}
    virtual void echo(){cout<<"Base class"<<endl;}
};

class CDerived:public CBase{
private:
    int m_value;
public:
    int getValue(){return m_value;}
};

void derive2base(){
     CDerived obj;
     CBase *ptr =  dynamic_cast<CBase *>(&obj);
     CBase& ref = dynamic_cast<CBase&>(obj);
     ref.echo();
}

void derive2base2(){
     CDerived obj;
     CBase *ptr =  (CBase *)&obj;
     CBase& ref = (CBase&)obj;
     ref.echo();
}

void base2derive(){
     CBase obj;
     CDerived *ptr =  dynamic_cast<CDerived *>(&obj);
     if(!ptr)
      cout<<"无法将指针转换成CDerived";
}

void base2deriveRef(){
     CBase obj;
     try{
        CDerived derive =  dynamic_cast<CDerived&>(obj);
     }
     catch(bad_cast& e)
     {
        cout<<"无法将对象转换成CDerived:";
     }
}

void base2derive2(){
     CBase* pObj = new CDerived();
     CDerived *ptr =  dynamic_cast<CDerived *>(pObj);
     if(ptr)
        cout<<"成功将指针转换成CDerived";
}




int main(){
    CBase objA;

    //无法成功转换
    CDerived *pObj = dynamic_cast<CDerived *>(&objA);
    if(pObj)
        cout<<pObj->getValue()<<endl;

    derive2base();
    base2deriveRef();
}