#include<iostream>
#include<string>
using namespace std;
//通过全局函数打印Person信息

template<class T1,class T2>
class Person;

template<class T1,class T2>
void showInfo2(Person <T1,T2>p){    //2.全局函数，类外实现(友元),提前声明
        cout<<"Name : "<<p.m_Name<<"\t Age : "<<p.m_Age<<endl;
}


template<class T1,class T2>
class Person
{

friend void showInfo(Person <T1,T2>p){  //1.全局函数，类内实现(友元)
        cout<<"Name : "<<p.m_Name<<"\t Age : "<<p.m_Age<<endl;
}
friend void showInfo2<>(Person <T1,T2>p);   //2.类外实现，<>加空函数模版，
private:
    T1 m_Name;
    T2 m_Age;
public:
    Person(T1 name,T2 age);
};

template<class T1,class T2>
Person<T1,T2>::Person(T1 name,T2 age)
{
    this->m_Name = name;
    this->m_Age = age;
}


void test01(){
    Person<string,int> p("Tom",20);
    showInfo(p);
}

void test02(){
    Person<string,int> p2("Jerry",20);
    showInfo2(p2);
}

int main(){
    //test01();
    test02();
}