#include<iostream>
#include<string>
using namespace std;
class Person
{
private:
    int m_A;
    mutable int m_B;        //特殊值
public:
    mutable int m_C;
    void showPerson()const;
    void func();
    Person(/* args */);
};

void Person::showPerson()const{     //const Person * const this
    this->m_B = 10;     //mutable 可修改
    cout<<"m_B :\t"<<m_B;
    //this->m_A = 100;  //不可修改
    //this = NULL;      //this指针 不可修改
    //如果没有const this均可修改，m_A = 100;可操作
}

Person::Person(/* args */)
{
}

void test01(){
    Person p;
    p.showPerson();
}

void test02(){
    const Person p;     //常对象，其属性不可修改
    p.m_C = 100;        //mutable 可修改
    p.showPerson();     //常对象 只能调用常函数
  //p.func();           //不可调用，因为逻辑可修改常对象，所以不接受
}

int main(){
    //test01();
}