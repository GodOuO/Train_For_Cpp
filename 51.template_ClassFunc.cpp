#include<iostream>
#include<string>
using namespace std;
//类模版 成员函数创建时机，在调用后创建

class Person1
{
private:
    /* data */
public:
    void showPerson1();
};
void Person1::showPerson1(){
    cout<<"Person1"<<endl;
}


class Person2
{
private:
    /* data */
public:
    void showPerson2();
};
void Person2::showPerson2(){
    cout<<"Person2"<<endl;
}


template<class T>
class mClass
{
private:
    T obj;          //T 类型 调用Person1和Person2类中的成员函数，可通过编译
public:
    void func1(){
        obj.showPerson1();
    }
    void func2(){
        obj.showPerson2();
    }
};


void test01(){
    mClass<Person1> m1;     //定义为Person1 没有showPerson2（）函数
    m1.func1();             //在Person1传入后 创建showPerson1（）

    mClass<Person2> m2;     //定义为Person2 没有showPerson1（）函数
    m2.func2();
}


int main(){
    test01();
}