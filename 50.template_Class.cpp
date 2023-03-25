#include<iostream>
#include<string>
using namespace std;
//类模版

template<class NameType,class AgeType = int>    //模版参数列表默认给定
class Person
{
private:
    NameType m_Name;
    AgeType m_Age;
public:
    Person(NameType name,AgeType age){
        m_Name = name;
        m_Age = age;
    }
    void shouInfo(){
        cout<<"Name : "<<m_Name<<"\tAge : "<<m_Age<<endl;
    }
};


void test01(){
    Person<string,int> p1("GodOuO",23); //模版参数列表
    p1.shouInfo();
}

void test02(){
    //Person p("GodOuO",1000);      //requires template arguments,无法自动类型推导
    Person<string,int> p("GodOuO",1000);    //只能显示指定类型
}

void test03(){
    Person<string> p1("Wendy",23);      //模版参数列表可以有默认参数
    p1.shouInfo();
}


int main(){
    //test01();
    //test02();
    test03();
}