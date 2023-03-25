#include<iostream>
#include<string>
using namespace std;
//模版的局限性

class Person
{
private:
    string m_Name;
    int m_Age;
public:
    string getName();
    int getAge();
    Person(string name,int age);
};
Person::Person(string name,int age)
{
    m_Name = name;
    m_Age = age;
}
string Person::getName(){
    return m_Name;
}
int Person::getAge(){
    return m_Age;
}

//对比两个数据是否相等
template<class T>
bool mCompare(T &a,T &b){
    if (a == b){
        return 1;
    }
    return 0; 
}

template<> bool mCompare(Person &a,Person &b){  //Person 具体化操作，重载Compare
    if (a.getAge() == b.getAge() && a.getName() == b.getName())
        return 1;
    return 0;
}


void test01(){
    int a = 10;
    int b = 20;
    cout<<mCompare(a,b)<<endl;
}

void test02(){
/* 
    1.运算符重载（33～.cpp - 37～.cpp）
    2.利用具体化Person 版本，具体化有限调用
 */
    Person p1("Tom",2);
    Person p2("Tom",2);
    cout<<mCompare(p1,p2)<<endl;
}


int main(){
    //test01();
    test02();
}