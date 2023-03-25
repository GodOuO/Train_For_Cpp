#pragma once
#include<iostream>
#include<string>
using namespace std;
//分文件编写

template<class T1,class T2>
class Person
{
private:
    T1 m_Name;
    T2 m_Age;
public:
    Person(T1 name,T2 age);
    void showInfo();
};

template<class T1,class T2>
Person<T1,T2>::Person(T1 name,T2 age)
{
    this->m_Name = name;
    this->m_Age = age;
}

template<class T1,class T2>
void Person<T1,T2>::showInfo(){
    cout<<"Name : "<<this->m_Name<<"\tAge ; "<<this->m_Age<<endl;
}