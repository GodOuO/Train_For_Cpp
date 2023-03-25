#include<iostream>
#include<string>
using namespace std;
//类模版对象 做 函数参数
template<class T1,class T2>
class Person
{
private:
    T1 m_Name;
    T2 m_Age;
public:
    Person(T1 name,T2 age){
        m_Name = name;
        m_Age = age;
    }
    void showPerson(){
        cout<<"Name : "<<this->m_Name<<"\tAge : "<<this->m_Age<<endl;
    }
};

void printPerson1(Person<string,int> &p){    //指定传入类型 赋值，最常用！
    p.showPerson();
}

void test01(){
    Person<string,int> p("GodOuO",23);
    printPerson1(p);
}

template<class T1,class T2>
void printPerson2(Person<T1,T2> &p){    //参数模版化（函数模版配类模版）
    p.showPerson();
    cout<<"T1 is : "<<typeid(T1).name()<<endl
        <<"T2 is : "<<typeid(T2).name()<<endl;  //查看数据类型（string）
}

void test02(){
    Person<string,int> p("Fuck",99);
    printPerson2(p);
}

template<class T>
void printPerson3(T &p){                //整个类模版化（函数模版配类模版）
    p.showPerson();
    cout<<"T is : "<<typeid(T).name()<<endl;
}

void test03(){
    Person<string,int> p("Guilty",100);
    printPerson3(p);
}

int main(){
    test01();
    test02();
    test03();
}