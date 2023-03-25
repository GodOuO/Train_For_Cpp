#include<iostream>
#include<string>
//#include"55.Person.cpp"       //1.直接包含源文件；visual studio 也需要调用 *.cpp
#include"55.Person.hpp"         //2.将 cpp 和 h 写入 hpp内调用
using namespace std;
//类模版 分文件编写问题解决

// template<class T1,class T2>
// class Person
// {
// private:
//     T1 m_Name;
//     T2 m_Age;
// public:
//     Person(T1 name,T2 age);
//     void showInfo();
// };

// template<class T1,class T2>
// Person<T1,T2>::Person(T1 name,T2 age)
// {
//     this->m_Name = name;
//     this->m_Age = age;
// }

// template<class T1,class T2>
// void Person<T1,T2>::showInfo(){
//     cout<<"Name : "<<this->m_Name<<"\tAge ; "<<this->m_Age<<endl;
// }


void test01(){
    Person<string,int> p("Jerry",20);
    p.showInfo();
}

int main(){
    test01();
}